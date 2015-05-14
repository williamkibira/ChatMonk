#include "domain/Friend.h"
#include <orm/domain_factory.h>
#ifdef _MSC_VER
#pragma warning(disable:4355)
#endif // _MSC_VER
namespace Domain {

Friend::Columns Friend::c;

namespace {
    Yb::Tables tbls;
    Yb::Relations rels;
    Yb::DomainMetaDataCreator<Friend> mdc(tbls, rels);
}

// AUTOGEN_BEGIN(008) {
Friend::Columns::Columns()
    : id(_T("id"), Yb::Value::LONGINT, 0, Yb::Column::PK, Yb::Value(), _T(""), _T(""), _T("id"), _T("id"))
    , first_name(_T("first_name"), Yb::Value::STRING, 25, Yb::Column::NULLABLE, Yb::Value(), _T(""), _T(""), _T("first-name"), _T("first_name"))
    , last_name(_T("last_name"), Yb::Value::STRING, 25, Yb::Column::NULLABLE, Yb::Value(), _T(""), _T(""), _T("last-name"), _T("last_name"))
    , email(_T("email"), Yb::Value::STRING, 40, Yb::Column::NULLABLE, Yb::Value(), _T(""), _T(""), _T("email"), _T("email"))
    , phone_number(_T("phone_number"), Yb::Value::STRING, 15, Yb::Column::NULLABLE, Yb::Value(), _T(""), _T(""), _T("phone-number"), _T("phone_number"))
    , photo_url(_T("photo_url"), Yb::Value::STRING, 100, Yb::Column::NULLABLE, Yb::Value(), _T(""), _T(""), _T("photo-url"), _T("photo_url"))
    , friend_id(_T("friend_id"), Yb::Value::STRING, 255, Yb::Column::NULLABLE, Yb::Value(), _T(""), _T(""), _T("friend-id"), _T("friend_id"))
{}

void Friend::Columns::fill_table(Yb::Table &tbl)
{
    tbl << id << first_name << last_name << email << phone_number << photo_url << friend_id;
}

void Friend::create_tables_meta(Yb::Tables &tbls)
{
    Yb::Table::Ptr t(new Yb::Table(_T("friend_tbl"), _T("friend"), _T("Friend")));
    t->set_seq_name(_T("seq_friend"));
    c.fill_table(*t);
    tbls.push_back(t);
}

void Friend::create_relations_meta(Yb::Relations &rels)
{
    {
        Yb::Relation::AttrMap attr1, attr2;
        attr1[_T("property")] = _T("groups");
        attr2[_T("property")] = _T("creator");
        Yb::Relation::Ptr r(new Yb::Relation(Yb::Relation::ONE2MANY, _T("Friend"), attr1, _T("Group"), attr2, Yb::Relation::Restrict));
        rels.push_back(r);
    }
}
// } AUTOGEN_END

Friend::Friend(Yb::DomainObject *owner, const Yb::String &prop_name)
    : Yb::DomainObject(*tbls[0], owner, prop_name)
// AUTOGEN_BEGIN(005) {
    , id(this, 0)
    , first_name(this, 1)
    , last_name(this, 2)
    , email(this, 3)
    , phone_number(this, 4)
    , photo_url(this, 5)
    , friend_id(this, 6)
    , groups(this, _T("groups"))
// } AUTOGEN_END
{}

Friend::Friend()
    : Yb::DomainObject(*tbls[0])
// AUTOGEN_BEGIN(005) {
    , id(this, 0)
    , first_name(this, 1)
    , last_name(this, 2)
    , email(this, 3)
    , phone_number(this, 4)
    , photo_url(this, 5)
    , friend_id(this, 6)
    , groups(this, _T("groups"))
// } AUTOGEN_END
{
// AUTOGEN_BEGIN(006) {
// } AUTOGEN_END
}

Friend::Friend(const Friend &other)
    : Yb::DomainObject(other)
// AUTOGEN_BEGIN(005) {
    , id(this, 0)
    , first_name(this, 1)
    , last_name(this, 2)
    , email(this, 3)
    , phone_number(this, 4)
    , photo_url(this, 5)
    , friend_id(this, 6)
    , groups(this, _T("groups"))
// } AUTOGEN_END
{}

Friend::Friend(Yb::Session &session)
    : Yb::DomainObject(session.schema(), _T("friend_tbl"))
// AUTOGEN_BEGIN(005) {
    , id(this, 0)
    , first_name(this, 1)
    , last_name(this, 2)
    , email(this, 3)
    , phone_number(this, 4)
    , photo_url(this, 5)
    , friend_id(this, 6)
    , groups(this, _T("groups"))
// } AUTOGEN_END
{
// AUTOGEN_BEGIN(006) {
// } AUTOGEN_END
    save(session);
}

Friend::Friend(Yb::DataObject::Ptr d)
    : Yb::DomainObject(d)
// AUTOGEN_BEGIN(005) {
    , id(this, 0)
    , first_name(this, 1)
    , last_name(this, 2)
    , email(this, 3)
    , phone_number(this, 4)
    , photo_url(this, 5)
    , friend_id(this, 6)
    , groups(this, _T("groups"))
// } AUTOGEN_END
{}

Friend::Friend(Yb::Session &session, const Yb::Key &key)
    : Yb::DomainObject(session, key)
// AUTOGEN_BEGIN(005) {
    , id(this, 0)
    , first_name(this, 1)
    , last_name(this, 2)
    , email(this, 3)
    , phone_number(this, 4)
    , photo_url(this, 5)
    , friend_id(this, 6)
    , groups(this, _T("groups"))
// } AUTOGEN_END
{}

Friend::Friend(Yb::Session &session, Yb::LongInt id)
    : Yb::DomainObject(session, _T("friend_tbl"), id)
// AUTOGEN_BEGIN(005) {
    , id(this, 0)
    , first_name(this, 1)
    , last_name(this, 2)
    , email(this, 3)
    , phone_number(this, 4)
    , photo_url(this, 5)
    , friend_id(this, 6)
    , groups(this, _T("groups"))
// } AUTOGEN_END
{}

Friend &Friend::operator=(const Friend &other)
{
    if (this != &other) {
        *(Yb::DomainObject *)this = (const Yb::DomainObject &)other;
    }
    return *this;
}

Friend::ListPtr
Friend::find(Yb::Session &session,
        const Yb::Expression &filter, const Yb::Expression &order_by)
{
    Friend::ListPtr lst(new Friend::List());
    Yb::ObjectList rows;
    session.load_collection(rows, Yb::Expression(_T("friend_tbl")), filter, order_by);
    if (rows.size()) {
        Yb::ObjectList::iterator it = rows.begin(), end = rows.end();
        for (; it != end; ++it)
            lst->push_back(Friend(*it));
    }
    return lst;
}

struct FriendRegistrator
{
    static void register_domain() {
        Yb::theDomainFactory().register_creator(_T("friend_tbl"),
            Yb::CreatorPtr(new Yb::DomainCreator<Friend>()));
    }
    FriendRegistrator() { register_domain(); }
};

static FriendRegistrator Friend_registrator;

} // end namespace Domain

// vim:ts=4:sts=4:sw=4:et:
