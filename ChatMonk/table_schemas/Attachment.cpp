#include "domain/Attachment.h"
#include <orm/domain_factory.h>
#ifdef _MSC_VER
#pragma warning(disable:4355)
#endif // _MSC_VER
namespace Domain {

Attachment::Columns Attachment::c;

namespace {
    Yb::Tables tbls;
    Yb::Relations rels;
    Yb::DomainMetaDataCreator<Attachment> mdc(tbls, rels);
}

// AUTOGEN_BEGIN(008) {
Attachment::Columns::Columns()
    : id(_T("id"), Yb::Value::LONGINT, 0, Yb::Column::PK, Yb::Value(), _T(""), _T(""), _T("id"), _T("id"))
    , message_id(_T("message_id"), Yb::Value::LONGINT, 0, Yb::Column::NULLABLE, Yb::Value(), _T("message_tbl"), _T("id"), _T("message-id"), _T("message_id"))
    , attachment_uri(_T("attachment_uri"), Yb::Value::STRING, 255, Yb::Column::NULLABLE, Yb::Value(), _T(""), _T(""), _T("attachment-uri"), _T("attachment_uri"))
{}

void Attachment::Columns::fill_table(Yb::Table &tbl)
{
    tbl << id << message_id << attachment_uri;
}

void Attachment::create_tables_meta(Yb::Tables &tbls)
{
    Yb::Table::Ptr t(new Yb::Table(_T("attachment_tbl"), _T("attachment"), _T("Attachment")));
    t->set_seq_name(_T("seq_attachment"));
    c.fill_table(*t);
    tbls.push_back(t);
}

void Attachment::create_relations_meta(Yb::Relations &rels)
{
    {
        Yb::Relation::AttrMap attr1, attr2;
        attr1[_T("property")] = _T("attachments");
        attr2[_T("property")] = _T("message");
        Yb::Relation::Ptr r(new Yb::Relation(Yb::Relation::ONE2MANY, _T("ChatMessageDB"), attr1, _T("Attachment"), attr2, Yb::Relation::Restrict));
        rels.push_back(r);
    }
}
// } AUTOGEN_END

Attachment::Attachment(Yb::DomainObject *owner, const Yb::String &prop_name)
    : Yb::DomainObject(*tbls[0], owner, prop_name)
// AUTOGEN_BEGIN(005) {
    , id(this, 0)
    , attachment_uri(this, 2)
    , message(this, _T("message"))
// } AUTOGEN_END
{}

Attachment::Attachment()
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

Attachment::Attachment(const Attachment &other)
    : Yb::DomainObject(other)
// AUTOGEN_BEGIN(005) {
    , id(this, 0)
    , attachment_uri(this, 2)
    , message(this, _T("message"))
// } AUTOGEN_END
{}

Attachment::Attachment(Yb::Session &session)
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

Attachment::Attachment(Yb::DataObject::Ptr d)
    : Yb::DomainObject(d)
// AUTOGEN_BEGIN(005) {
    , id(this, 0)
    , attachment_uri(this, 2)
    , message(this, _T("message"))
// } AUTOGEN_END
{}

Attachment::Attachment(Yb::Session &session, const Yb::Key &key)
    : Yb::DomainObject(session, key)
// AUTOGEN_BEGIN(005) {
    , id(this, 0)
    , attachment_uri(this, 2)
    , message(this, _T("message"))
// } AUTOGEN_END
{}

Attachment::Attachment(Yb::Session &session, Yb::LongInt id)
    : Yb::DomainObject(session, _T("attachment_tbl"), id)
// AUTOGEN_BEGIN(005) {
    , id(this, 0)
    , attachment_uri(this, 2)
    , message(this, _T("message"))
// } AUTOGEN_END
{}

Attachment &Attachment::operator=(const Attachment &other)
{
    if (this != &other) {
        *(Yb::DomainObject *)this = (const Yb::DomainObject &)other;
    }
    return *this;
}

Attachment::ListPtr
Attachment::find(Yb::Session &session,
        const Yb::Expression &filter, const Yb::Expression &order_by)
{
    Attachment::ListPtr lst(new Attachment::List());
    Yb::ObjectList rows;
    session.load_collection(rows, Yb::Expression(_T("attachment_tbl")), filter, order_by);
    if (rows.size()) {
        Yb::ObjectList::iterator it = rows.begin(), end = rows.end();
        for (; it != end; ++it)
            lst->push_back(Attachment(*it));
    }
    return lst;
}

struct AttachmentRegistrator
{
    static void register_domain() {
        Yb::theDomainFactory().register_creator(_T("attachment_tbl"),
            Yb::CreatorPtr(new Yb::DomainCreator<Attachment>()));
    }
    AttachmentRegistrator() { register_domain(); }
};

static AttachmentRegistrator Attachment_registrator;

} // end namespace Domain

// vim:ts=4:sts=4:sw=4:et:
