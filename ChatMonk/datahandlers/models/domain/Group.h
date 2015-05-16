#ifndef ORM_DOMAIN__GROUP__INCLUDED
#define ORM_DOMAIN__GROUP__INCLUDED

#include <yb/orm/domain_object.h>
// AUTOGEN_BEGIN(001) {
#include "Friend.h"
// } AUTOGEN_END

namespace Domain {

// AUTOGEN_BEGIN(002) {
// } AUTOGEN_END

class Group;
typedef Yb::DomainObjHolder<Group> GroupHolder;

class Group: public Yb::DomainObject
{
public:
    typedef Yb::DomainObjHolder<Group> Holder;
// AUTOGEN_BEGIN(007) {
    struct Columns {
        Yb::Column id, creator_id, group_name, group_description, group_id, group_photo_uri, unique_id, activated;
        Columns();
        void fill_table(Yb::Table &tbl);
    };
    static Columns c;
// } AUTOGEN_END
    static const Yb::String get_table_name() { return _T("group_tbl"); }
    typedef Yb::DomainResultSet<Group> ResultSet;
    // static method 'find'
    typedef std::vector<Group> List;
    typedef std::auto_ptr<List> ListPtr;
    static ListPtr find(Yb::Session &session,
            const Yb::Expression &filter, const Yb::Expression &order_by = Yb::Expression());
    // constructors
    Group(Yb::DomainObject *owner, const Yb::String &prop_name);
    Group();
    Group(const Group &other);
    explicit Group(Yb::Session &session);
    explicit Group(Yb::DataObject::Ptr d);
    Group(Yb::Session &session, const Yb::Key &key);
    Group(Yb::Session &session, Yb::LongInt id);
    Group &operator=(const Group &other);
    static void create_tables_meta(Yb::Tables &tbls);
    static void create_relations_meta(Yb::Relations &rels);
// AUTOGEN_BEGIN(003) {
    // properties
    Yb::Property<Yb::LongInt> id;
    Yb::Property<Yb::String> group_name;
    Yb::Property<Yb::String> group_description;
    Yb::Property<Yb::String> group_id;
    Yb::Property<Yb::String> group_photo_uri;
    Yb::Property<Yb::String> unique_id;
    Yb::Property<Yb::String> activated;
    // relation properties
    Friend::Holder creator;
// } AUTOGEN_END
};

} // namespace Domain

// vim:ts=4:sts=4:sw=4:et:
#endif
