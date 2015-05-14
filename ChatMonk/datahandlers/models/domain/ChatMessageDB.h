#ifndef ORM_DOMAIN__CHATMESSAGEDB__INCLUDED
#define ORM_DOMAIN__CHATMESSAGEDB__INCLUDED

#include <yb/orm/domain_object.h>
// AUTOGEN_BEGIN(001) {
// } AUTOGEN_END

namespace Domain {

// AUTOGEN_BEGIN(002) {
class Attachment;
typedef Yb::DomainObjHolder<Attachment> AttachmentHolder;
// } AUTOGEN_END

class ChatMessageDB;
typedef Yb::DomainObjHolder<ChatMessageDB> ChatMessageDBHolder;

class ChatMessageDB: public Yb::DomainObject
{
public:
    typedef Yb::DomainObjHolder<ChatMessageDB> Holder;
// AUTOGEN_BEGIN(007) {
    struct Columns {
        Yb::Column id, message_data, sender_id, receiver_id;
        Columns();
        void fill_table(Yb::Table &tbl);
    };
    static Columns c;
// } AUTOGEN_END
    static const Yb::String get_table_name() { return _T("message_tbl"); }
    typedef Yb::DomainResultSet<ChatMessageDB> ResultSet;
    // static method 'find'
    typedef std::vector<ChatMessageDB> List;
    typedef std::auto_ptr<List> ListPtr;
    static ListPtr find(Yb::Session &session,
            const Yb::Expression &filter, const Yb::Expression &order_by = Yb::Expression());
    // constructors
    ChatMessageDB(Yb::DomainObject *owner, const Yb::String &prop_name);
    ChatMessageDB();
    ChatMessageDB(const ChatMessageDB &other);
    explicit ChatMessageDB(Yb::Session &session);
    explicit ChatMessageDB(Yb::DataObject::Ptr d);
    ChatMessageDB(Yb::Session &session, const Yb::Key &key);
    ChatMessageDB(Yb::Session &session, Yb::LongInt id);
    ChatMessageDB &operator=(const ChatMessageDB &other);
    static void create_tables_meta(Yb::Tables &tbls);
    static void create_relations_meta(Yb::Relations &rels);
// AUTOGEN_BEGIN(003) {
    // properties
    Yb::Property<Yb::LongInt> id;
    Yb::Property<Yb::String> message_data;
    Yb::Property<Yb::String> sender_id;
    Yb::Property<Yb::String> receiver_id;
    // relation properties
    Yb::ManagedList<Attachment> attachments;
// } AUTOGEN_END
};

} // namespace Domain

// vim:ts=4:sts=4:sw=4:et:
#endif
