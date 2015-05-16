#include "domain/ChatMessageDB.h"
#include <orm/domain_factory.h>
#ifdef _MSC_VER
#pragma warning(disable:4355)
#endif // _MSC_VER
namespace Domain {

ChatMessageDB::Columns ChatMessageDB::c;

namespace {
    Yb::Tables tbls;
    Yb::Relations rels;
    Yb::DomainMetaDataCreator<ChatMessageDB> mdc(tbls, rels);
}

// AUTOGEN_BEGIN(008) {
ChatMessageDB::Columns::Columns()
    : id(_T("id"), Yb::Value::LONGINT, 0, Yb::Column::PK, Yb::Value(), _T(""), _T(""), _T("id"), _T("id"))
    , message_data(_T("message_data"), Yb::Value::STRING, 500, Yb::Column::NULLABLE, Yb::Value(), _T(""), _T(""), _T("message-data"), _T("message_data"))
    , sender_id(_T("sender_id"), Yb::Value::STRING, 255, Yb::Column::NULLABLE, Yb::Value(), _T(""), _T(""), _T("sender-id"), _T("sender_id"))
    , receiver_id(_T("receiver_id"), Yb::Value::STRING, 255, Yb::Column::NULLABLE, Yb::Value(), _T(""), _T(""), _T("receiver-id"), _T("receiver_id"))
    , message_type(_T("message_type"), Yb::Value::STRING, 10, Yb::Column::NULLABLE, Yb::Value(), _T(""), _T(""), _T("message-type"), _T("message_type"))
{}

void ChatMessageDB::Columns::fill_table(Yb::Table &tbl)
{
    tbl << id << message_data << sender_id << receiver_id << message_type;
}

void ChatMessageDB::create_tables_meta(Yb::Tables &tbls)
{
    Yb::Table::Ptr t(new Yb::Table(_T("message_tbl"), _T("message"), _T("ChatMessageDB")));
    t->set_seq_name(_T("seq_message"));
    c.fill_table(*t);
    tbls.push_back(t);
}

void ChatMessageDB::create_relations_meta(Yb::Relations &rels)
{
    {
        Yb::Relation::AttrMap attr1, attr2;
        attr1[_T("property")] = _T("attachments");
        attr2[_T("property")] = _T("message");
        Yb::Relation::Ptr r(new Yb::Relation(Yb::Relation::ONE2MANY, _T("ChatMessageDB"), attr1, _T("AttachmentDB"), attr2, Yb::Relation::Restrict));
        rels.push_back(r);
    }
}
// } AUTOGEN_END

ChatMessageDB::ChatMessageDB(Yb::DomainObject *owner, const Yb::String &prop_name)
    : Yb::DomainObject(*tbls[0], owner, prop_name)
// AUTOGEN_BEGIN(005) {
    , id(this, 0)
    , message_data(this, 1)
    , sender_id(this, 2)
    , receiver_id(this, 3)
    , message_type(this, 4)
    , attachments(this, _T("attachments"))
// } AUTOGEN_END
{}

ChatMessageDB::ChatMessageDB()
    : Yb::DomainObject(*tbls[0])
// AUTOGEN_BEGIN(005) {
    , id(this, 0)
    , message_data(this, 1)
    , sender_id(this, 2)
    , receiver_id(this, 3)
    , message_type(this, 4)
    , attachments(this, _T("attachments"))
// } AUTOGEN_END
{
// AUTOGEN_BEGIN(006) {
// } AUTOGEN_END
}

ChatMessageDB::ChatMessageDB(const ChatMessageDB &other)
    : Yb::DomainObject(other)
// AUTOGEN_BEGIN(005) {
    , id(this, 0)
    , message_data(this, 1)
    , sender_id(this, 2)
    , receiver_id(this, 3)
    , message_type(this, 4)
    , attachments(this, _T("attachments"))
// } AUTOGEN_END
{}

ChatMessageDB::ChatMessageDB(Yb::Session &session)
    : Yb::DomainObject(session.schema(), _T("message_tbl"))
// AUTOGEN_BEGIN(005) {
    , id(this, 0)
    , message_data(this, 1)
    , sender_id(this, 2)
    , receiver_id(this, 3)
    , message_type(this, 4)
    , attachments(this, _T("attachments"))
// } AUTOGEN_END
{
// AUTOGEN_BEGIN(006) {
// } AUTOGEN_END
    save(session);
}

ChatMessageDB::ChatMessageDB(Yb::DataObject::Ptr d)
    : Yb::DomainObject(d)
// AUTOGEN_BEGIN(005) {
    , id(this, 0)
    , message_data(this, 1)
    , sender_id(this, 2)
    , receiver_id(this, 3)
    , message_type(this, 4)
    , attachments(this, _T("attachments"))
// } AUTOGEN_END
{}

ChatMessageDB::ChatMessageDB(Yb::Session &session, const Yb::Key &key)
    : Yb::DomainObject(session, key)
// AUTOGEN_BEGIN(005) {
    , id(this, 0)
    , message_data(this, 1)
    , sender_id(this, 2)
    , receiver_id(this, 3)
    , message_type(this, 4)
    , attachments(this, _T("attachments"))
// } AUTOGEN_END
{}

ChatMessageDB::ChatMessageDB(Yb::Session &session, Yb::LongInt id)
    : Yb::DomainObject(session, _T("message_tbl"), id)
// AUTOGEN_BEGIN(005) {
    , id(this, 0)
    , message_data(this, 1)
    , sender_id(this, 2)
    , receiver_id(this, 3)
    , message_type(this, 4)
    , attachments(this, _T("attachments"))
// } AUTOGEN_END
{}

ChatMessageDB &ChatMessageDB::operator=(const ChatMessageDB &other)
{
    if (this != &other) {
        *(Yb::DomainObject *)this = (const Yb::DomainObject &)other;
    }
    return *this;
}

ChatMessageDB::ListPtr
ChatMessageDB::find(Yb::Session &session,
        const Yb::Expression &filter, const Yb::Expression &order_by)
{
    ChatMessageDB::ListPtr lst(new ChatMessageDB::List());
    Yb::ObjectList rows;
    session.load_collection(rows, Yb::Expression(_T("message_tbl")), filter, order_by);
    if (rows.size()) {
        Yb::ObjectList::iterator it = rows.begin(), end = rows.end();
        for (; it != end; ++it)
            lst->push_back(ChatMessageDB(*it));
    }
    return lst;
}

struct ChatMessageDBRegistrator
{
    static void register_domain() {
        Yb::theDomainFactory().register_creator(_T("message_tbl"),
            Yb::CreatorPtr(new Yb::DomainCreator<ChatMessageDB>()));
    }
    ChatMessageDBRegistrator() { register_domain(); }
};

static ChatMessageDBRegistrator ChatMessageDB_registrator;

} // end namespace Domain

// vim:ts=4:sts=4:sw=4:et:
