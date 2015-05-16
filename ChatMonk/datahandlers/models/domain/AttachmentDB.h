#ifndef ORM_DOMAIN__ATTACHMENTDB__INCLUDED
#define ORM_DOMAIN__ATTACHMENTDB__INCLUDED

#include <yb/orm/domain_object.h>
// AUTOGEN_BEGIN(001) {
#include "ChatMessageDB.h"
// } AUTOGEN_END

namespace Domain {

// AUTOGEN_BEGIN(002) {
// } AUTOGEN_END

class AttachmentDB;
typedef Yb::DomainObjHolder<AttachmentDB> AttachmentDBHolder;

class AttachmentDB: public Yb::DomainObject
{
public:
    typedef Yb::DomainObjHolder<AttachmentDB> Holder;
// AUTOGEN_BEGIN(007) {
    struct Columns {
        Yb::Column id, message_id, attachment_uri;
        Columns();
        void fill_table(Yb::Table &tbl);
    };
    static Columns c;
// } AUTOGEN_END
    static const Yb::String get_table_name() { return _T("attachment_tbl"); }
    typedef Yb::DomainResultSet<AttachmentDB> ResultSet;
    // static method 'find'
    typedef std::vector<AttachmentDB> List;
    typedef std::auto_ptr<List> ListPtr;
    static ListPtr find(Yb::Session &session,
            const Yb::Expression &filter, const Yb::Expression &order_by = Yb::Expression());
    // constructors
    AttachmentDB(Yb::DomainObject *owner, const Yb::String &prop_name);
    AttachmentDB();
    AttachmentDB(const AttachmentDB &other);
    explicit AttachmentDB(Yb::Session &session);
    explicit AttachmentDB(Yb::DataObject::Ptr d);
    AttachmentDB(Yb::Session &session, const Yb::Key &key);
    AttachmentDB(Yb::Session &session, Yb::LongInt id);
    AttachmentDB &operator=(const AttachmentDB &other);
    static void create_tables_meta(Yb::Tables &tbls);
    static void create_relations_meta(Yb::Relations &rels);
// AUTOGEN_BEGIN(003) {
    // properties
    Yb::Property<Yb::LongInt> id;
    Yb::Property<Yb::String> attachment_uri;
    // relation properties
    ChatMessageDB::Holder message;
// } AUTOGEN_END
};

} // namespace Domain

// vim:ts=4:sts=4:sw=4:et:
#endif
