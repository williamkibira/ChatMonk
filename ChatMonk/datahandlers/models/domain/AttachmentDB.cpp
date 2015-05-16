#include "domain/AttachmentDB.h"
#include <orm/domain_factory.h>
#ifdef _MSC_VER
#pragma warning(disable:4355)
#endif // _MSC_VER
namespace Domain {

AttachmentDB::Columns AttachmentDB::c;

namespace {
    Yb::Tables tbls;
    Yb::Relations rels;
    Yb::DomainMetaDataCreator<AttachmentDB> mdc(tbls, rels);
}

// AUTOGEN_BEGIN(008) {
AttachmentDB::Columns::Columns()
    : id(_T("id"), Yb::Value::LONGINT, 0, Yb::Column::PK, Yb::Value(), _T(""), _T(""), _T("id"), _T("id"))
    , message_id(_T("message_id"), Yb::Value::LONGINT, 0, Yb::Column::NULLABLE, Yb::Value(), _T("message_tbl"), _T("id"), _T("message-id"), _T("message_id"))
    , attachment_uri(_T("attachment_uri"), Yb::Value::STRING, 255, Yb::Column::NULLABLE, Yb::Value(), _T(""), _T(""), _T("attachment-uri"), _T("attachment_uri"))
{}

void AttachmentDB::Columns::fill_table(Yb::Table &tbl)
{
    tbl << id << message_id << attachment_uri;
}

void AttachmentDB::create_tables_meta(Yb::Tables &tbls)
{
    Yb::Table::Ptr t(new Yb::Table(_T("attachment_tbl"), _T("attachment"), _T("AttachmentDB")));
    t->set_seq_name(_T("seq_attachment"));
    c.fill_table(*t);
    tbls.push_back(t);
}

void AttachmentDB::create_relations_meta(Yb::Relations &rels)
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

AttachmentDB::AttachmentDB(Yb::DomainObject *owner, const Yb::String &prop_name)
    : Yb::DomainObject(*tbls[0], owner, prop_name)
// AUTOGEN_BEGIN(005) {
    , id(this, 0)
    , attachment_uri(this, 2)
    , message(this, _T("message"))
// } AUTOGEN_END
{}

AttachmentDB::AttachmentDB()
    : Yb::DomainObject(*tbls[0])
// AUTOGEN_BEGIN(005) {
    , id(this, 0)
    , attachment_uri(this, 2)
    , message(this, _T("message"))
// } AUTOGEN_END
{
// AUTOGEN_BEGIN(006) {
// } AUTOGEN_END
}

AttachmentDB::AttachmentDB(const AttachmentDB &other)
    : Yb::DomainObject(other)
// AUTOGEN_BEGIN(005) {
    , id(this, 0)
    , attachment_uri(this, 2)
    , message(this, _T("message"))
// } AUTOGEN_END
{}

AttachmentDB::AttachmentDB(Yb::Session &session)
    : Yb::DomainObject(session.schema(), _T("attachment_tbl"))
// AUTOGEN_BEGIN(005) {
    , id(this, 0)
    , attachment_uri(this, 2)
    , message(this, _T("message"))
// } AUTOGEN_END
{
// AUTOGEN_BEGIN(006) {
// } AUTOGEN_END
    save(session);
}

AttachmentDB::AttachmentDB(Yb::DataObject::Ptr d)
    : Yb::DomainObject(d)
// AUTOGEN_BEGIN(005) {
    , id(this, 0)
    , attachment_uri(this, 2)
    , message(this, _T("message"))
// } AUTOGEN_END
{}

AttachmentDB::AttachmentDB(Yb::Session &session, const Yb::Key &key)
    : Yb::DomainObject(session, key)
// AUTOGEN_BEGIN(005) {
    , id(this, 0)
    , attachment_uri(this, 2)
    , message(this, _T("message"))
// } AUTOGEN_END
{}

AttachmentDB::AttachmentDB(Yb::Session &session, Yb::LongInt id)
    : Yb::DomainObject(session, _T("attachment_tbl"), id)
// AUTOGEN_BEGIN(005) {
    , id(this, 0)
    , attachment_uri(this, 2)
    , message(this, _T("message"))
// } AUTOGEN_END
{}

AttachmentDB &AttachmentDB::operator=(const AttachmentDB &other)
{
    if (this != &other) {
        *(Yb::DomainObject *)this = (const Yb::DomainObject &)other;
    }
    return *this;
}

AttachmentDB::ListPtr
AttachmentDB::find(Yb::Session &session,
        const Yb::Expression &filter, const Yb::Expression &order_by)
{
    AttachmentDB::ListPtr lst(new AttachmentDB::List());
    Yb::ObjectList rows;
    session.load_collection(rows, Yb::Expression(_T("attachment_tbl")), filter, order_by);
    if (rows.size()) {
        Yb::ObjectList::iterator it = rows.begin(), end = rows.end();
        for (; it != end; ++it)
            lst->push_back(AttachmentDB(*it));
    }
    return lst;
}

struct AttachmentDBRegistrator
{
    static void register_domain() {
        Yb::theDomainFactory().register_creator(_T("attachment_tbl"),
            Yb::CreatorPtr(new Yb::DomainCreator<AttachmentDB>()));
    }
    AttachmentDBRegistrator() { register_domain(); }
};

static AttachmentDBRegistrator AttachmentDB_registrator;

} // end namespace Domain

// vim:ts=4:sts=4:sw=4:et:
