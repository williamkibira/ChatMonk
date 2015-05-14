// -*- Mode: C++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: nil; -*-
#ifndef YB__ORM__SQL_POOL__INCLUDED
#define YB__ORM__SQL_POOL__INCLUDED

#include <map>
#include <deque>
#include "util/thread.h"
#include "orm_config.h"
#include "sql_driver.h"

namespace Yb {

#define YB_POOL_MAX_SIZE 10
#define YB_POOL_IDLE_TIME 30 // sec.
#define YB_POOL_MONITOR_SLEEP 2 // sec.
#define YB_POOL_WAIT_TIME 20 // sec.

class SqlPool;

class YBORM_DECL PoolError: public DBError
{
public:
    PoolError(const String &err);
};

class YBORM_DECL PoolMonThread: public Thread
{
    SqlPool *pool_;
public:
    PoolMonThread(SqlPool *pool);
    void on_run();
};

class YBORM_DECL SqlPool
{
    friend class PoolMonThread;
public:
    typedef SqlConnection *SqlConnectionPtr;
    SqlPool(int pool_max_size = YB_POOL_MAX_SIZE,
            int idle_time = YB_POOL_IDLE_TIME,
            int monitor_sleep = YB_POOL_MONITOR_SLEEP,
            ILogger *logger = NULL);
    ~SqlPool();
    void add_source(const SqlSource &source);
    SqlConnectionPtr get(const String &id, int timeout = YB_POOL_WAIT_TIME);
    void put(SqlConnectionPtr handle, bool close_now = false, bool new_conn = false);

private:
    std::map<String, SqlSource> sources_;
    std::map<String, int> counts_;
    typedef std::deque<SqlConnectionPtr> Pool;
    std::map<String, Pool> pools_;
    typedef std::deque<std::exception> OpenErrors;
    std::map<String, OpenErrors> open_errors_;
    std::deque<String> connections_for_open_;
    std::deque<SqlConnectionPtr> connections_for_delete_;
    Mutex pool_mux_, stop_mux_;
    Condition pool_cond_, stop_cond_;
    int pool_max_size_, idle_time_, monitor_sleep_;
    bool stop_monitor_flag_;
    PoolMonThread monitor_;
    ILogger::Ptr logger_;

    void *monitor_thread();
    void close_all();
    void stop_monitor_thread();
    bool sleep_not_stop();
    const String get_stats(const String &source_id);
};

class YBORM_DECL SqlPoolDescr
{
    SqlPool &pool_;
    String source_id_;
    int timeout_;
public:
    SqlPoolDescr(SqlPool &pool, const String &source_id, int timeout)
        : pool_(pool)
        , source_id_(source_id)
        , timeout_(timeout)
    {}
    SqlPool &get_pool() const { return pool_; }
    const String &get_source_id() const { return source_id_; }
    int get_timeout() const { return timeout_; }
};

class YBORM_DECL SqlConnectionVar: NonCopyable
{
    SqlPool &pool_;
    SqlConnection *handle_;
public:
    explicit SqlConnectionVar(const SqlPoolDescr &d);
    SqlConnectionVar(SqlPool &pool, const String &source_id,
                 int timeout = YB_POOL_WAIT_TIME);
    ~SqlConnectionVar();
    SqlConnection *operator-> () const;
};

} // namespace Yb

// vim:ts=4:sts=4:sw=4:et:
#endif // YB__ORM__SQL_POOL__INCLUDED
