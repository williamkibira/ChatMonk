#ifndef ORM_DOMAIN__ATTACHMENT__INCLUDED
#define ORM_DOMAIN__ATTACHMENT__INCLUDED

#include <orm/domain_object.h>
// AUTOGEN_BEGIN(001) {
#include "domain/ChatMessageDB.h"
// } AUTOGEN_END

namespace Domain {

// AUTOGEN_BEGIN(002) {
// } AUTOGEN_END

class Attachment;
typedef Yb::DomainObjHolder<Attachment> AttachmentHolder;

class Attachment: public Yb::DomainObject
{
public:
    typedef Yb::DomainObjHolder<Attachment> Holder;
// AUTOGEN_BEGIN(007) {
    struct Columns {
        Yb::Column id, message_id, attachment_uri;
        Columns();
        void fill_table(Yb::Table &tbl);
    };
    static Columns c;
// } AUTOGEN_END
    static const Yb::String get_table_name() { return _T("attachment_tbl"); }
    typedef Yb::DomainResultSet<Attachment> ResultSet;
    // static method 'find'
    typedef std::vector<Attachment> List;
    typedef std::auto_ptr<List> ListPtr;
    static ListPtr find(Yb::Session &session,
            const Yb::Expression &filter, const Yb::Expression &order_by = Yb::Expression());
    // constructors
    Attachment(Yb::DomainObject *owner, const Yb::String &prop_name);
    Attachment();
    Attachment(const Attachment &other);
    explicit Attachment(Yb::Session &session);
    explicit Attachment(Yb::DataObject::Ptr d);
    Attachment(Yb::Session &session, const Yb::Key &key);
    Attachment(Yb::Session &session, Yb::LongInt id);
    Attachment &operator=(const Attachment &other);
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
