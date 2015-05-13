#include "domain/Invitation.h"
#include <orm/domain_factory.h>
#ifdef _MSC_VER
#pragma warning(disable:4355)
#endif // _MSC_VER
namespace Domain {

Invitation::Columns Invitation::c;

namespace {
    Yb::Tables tbls;
    Yb::Relations rels;
    Yb::DomainMetaDataCreator<Invitation> mdc(tbls, rels);
}

// AUTOGEN_BEGIN(008) {
Invitation::Columns::Columns()
    : id(_T("id"), Yb::Value::LONGINT, 0, Yb::Column::PK, Yb::Value(), _T(""), _T(""), _T("id"), _T("id"))
    , group_id(_T("group_id"), Yb::Value::LONGINT, 0, 0, Yb::Value(), _T("group_tbl"), _T("id"), _T("group-id"), _T("group_id"))
    , private_message(_T("private_message"), Yb::Value::STRING, 150, Yb::Column::NULLABLE, Yb::Value(), _T(""), _T(""), _T("private-message"), _T("private_message"))
    , unique_id(_T("unique_id"), Yb::Value::STRING, 255, Yb::Column::NULLABLE, Yb::Value(), _T(""), _T(""), _T("unique-id"), _T("unique_id"))
{}

void Invitation::Columns::fill_table(Yb::Table &tbl)
{
    tbl << id << group_id << private_message << unique_id;
}

void Invitation::create_tables_meta(Yb::Tables &tbls)
{
    Yb::Table::Ptr t(new Yb::Table(_T("invitation_tbl"), _T("invitation"), _T("Invitation")));
    t->set_seq_name(_T("seq_invitation"));
    c.fill_table(*t);
    tbls.push_back(t);
}

void Invitation::create_relations_meta(Yb::Relations &rels)
{
}
// } AUTOGEN_END

Invitation::Invitation(Yb::DomainObject *owner, const Yb::String &prop_name)
    : Yb::DomainObject(*tbls[0], owner, prop_name)
// AUTOGEN_BEGIN(005) {
    , id(this, 0)
    , private_message(this, 2)
    , unique_id(this, 3)
// } AUTOGEN_END
{}

Invitation::Invitation()
    : Yb::DomainObject(*tbls[0])
// AUTOGEN_BEGIN(005) {
    , id(this, 0)
    , private_message(this, 2)
    , unique_id(this, 3)
// } AUTOGEN_END
{
// AUTOGEN_BEGIN(006) {
// } AUTOGEN_END
}

Invitation::Invitation(const Invitation &other)
    : Yb::DomainObject(other)
// AUTOGEN_BEGIN(005) {
    , id(this, 0)
    , private_message(this, 2)
    , unique_id(this, 3)
// } AUTOGEN_END
{}

Invitation::Invitation(Yb::Session &session)
    : Yb::DomainObject(session.schema(), _T("invitation_tbl"))
// AUTOGEN_BEGIN(005) {
    , id(this, 0)
    , private_message(this, 2)
    , unique_id(this, 3)
// } AUTOGEN_END
{
// AUTOGEN_BEGIN(006) {
// } AUTOGEN_END
    save(session);
}

Invitation::Invitation(Yb::DataObject::Ptr d)
    : Yb::DomainObject(d)
// AUTOGEN_BEGIN(005) {
    , id(this, 0)
    , private_message(this, 2)
    , unique_id(this, 3)
// } AUTOGEN_END
{}

Invitation::Invitation(Yb::Session &session, const Yb::Key &key)
    : Yb::DomainObject(session, key)
// AUTOGEN_BEGIN(005) {
    , id(this, 0)
    , private_message(this, 2)
    , unique_id(this, 3)
// } AUTOGEN_END
{}

Invitation::Invitation(Yb::Session &session, Yb::LongInt id)
    : Yb::DomainObject(session, _T("invitation_tbl"), id)
// AUTOGEN_BEGIN(005) {
    , id(this, 0)
    , private_message(this, 2)
    , unique_id(this, 3)
// } AUTOGEN_END
{}

Invitation &Invitation::operator=(const Invitation &other)
{
    if (this != &other) {
        *(Yb::DomainObject *)this = (const Yb::DomainObject &)other;
    }
    return *this;
}

Invitation::ListPtr
Invitation::find(Yb::Session &session,
        const Yb::Expression &filter, const Yb::Expression &order_by)
{
    Invitation::ListPtr lst(new Invitation::List());
    Yb::ObjectList rows;
    session.load_collection(rows, Yb::Expression(_T("invitation_tbl")), filter, order_by);
    if (rows.size()) {
        Yb::ObjectList::iterator it = rows.begin(), end = rows.end();
        for (; it != end; ++it)
            lst->push_back(Invitation(*it));
    }
    return lst;
}

struct InvitationRegistrator
{
    static void register_domain() {
        Yb::theDomainFactory().register_creator(_T("invitation_tbl"),
            Yb::CreatorPtr(new Yb::DomainCreator<Invitation>()));
    }
    InvitationRegistrator() { register_domain(); }
};

static InvitationRegistrator Invitation_registrator;

} // end namespace Domain

// vim:ts=4:sts=4:sw=4:et:
