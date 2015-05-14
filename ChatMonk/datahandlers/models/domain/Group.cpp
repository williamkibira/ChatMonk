#include "domain/Group.h"
#include <orm/domain_factory.h>
#ifdef _MSC_VER
#pragma warning(disable:4355)
#endif // _MSC_VER
namespace Domain {

Group::Columns Group::c;

namespace {
    Yb::Tables tbls;
    Yb::Relations rels;
    Yb::DomainMetaDataCreator<Group> mdc(tbls, rels);
}

// AUTOGEN_BEGIN(008) {
Group::Columns::Columns()
    : id(_T("id"), Yb::Value::LONGINT, 0, Yb::Column::PK, Yb::Value(), _T(""), _T(""), _T("id"), _T("id"))
    , creator_id(_T("creator_id"), Yb::Value::LONGINT, 0, 0, Yb::Value(), _T("friend_tbl"), _T("id"), _T("creator-id"), _T("creator_id"))
    , group_name(_T("group_name"), Yb::Value::STRING, 25, Yb::Column::NULLABLE, Yb::Value(), _T(""), _T(""), _T("group-name"), _T("group_name"))
    , group_description(_T("group_description"), Yb::Value::STRING, 150, Yb::Column::NULLABLE, Yb::Value(), _T(""), _T(""), _T("group-description"), _T("group_description"))
    , group_id(_T("group_id"), Yb::Value::STRING, 225, Yb::Column::NULLABLE, Yb::Value(), _T(""), _T(""), _T("group-id"), _T("group_id"))
    , group_photo_uri(_T("group_photo_uri"), Yb::Value::STRING, 100, Yb::Column::NULLABLE, Yb::Value(), _T(""), _T(""), _T("group-photo-uri"), _T("group_photo_uri"))
    , unique_id(_T("unique_id"), Yb::Value::STRING, 255, Yb::Column::NULLABLE, Yb::Value(), _T(""), _T(""), _T("unique-id"), _T("unique_id"))
    , activated(_T("activated"), Yb::Value::STRING, 14, Yb::Column::NULLABLE, Yb::Value(_T("DE-ACTIVATED")), _T(""), _T(""), _T("activated"), _T("activated"))
{}

void Group::Columns::fill_table(Yb::Table &tbl)
{
    tbl << id << creator_id << group_name << group_description << group_id << group_photo_uri << unique_id << activated;
}

void Group::create_tables_meta(Yb::Tables &tbls)
{
    Yb::Table::Ptr t(new Yb::Table(_T("group_tbl"), _T("group"), _T("Group")));
    t->set_seq_name(_T("seq_group"));
    c.fill_table(*t);
    tbls.push_back(t);
}

void Group::create_relations_meta(Yb::Relations &rels)
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

Group::Group(Yb::DomainObject *owner, const Yb::String &prop_name)
    : Yb::DomainObject(*tbls[0], owner, prop_name)
// AUTOGEN_BEGIN(005) {
    , id(this, 0)
    , group_name(this, 2)
    , group_description(this, 3)
    , group_id(this, 4)
    , group_photo_uri(this, 5)
    , unique_id(this, 6)
    , activated(this, 7)
    , creator(this, _T("creator"))
// } AUTOGEN_END
{}

Group::Group()
    : Yb::DomainObject(*tbls[0])
// AUTOGEN_BEGIN(005) {
    , id(this, 0)
    , group_name(this, 2)
    , group_description(this, 3)
    , group_id(this, 4)
    , group_photo_uri(this, 5)
    , unique_id(this, 6)
    , activated(this, 7)
    , creator(this, _T("creator"))
// } AUTOGEN_END
{
// AUTOGEN_BEGIN(006) {
    set(7, Yb::Value(_T("DE-ACTIVATED")));
// } AUTOGEN_END
}

Group::Group(const Group &other)
    : Yb::DomainObject(other)
// AUTOGEN_BEGIN(005) {
    , id(this, 0)
    , group_name(this, 2)
    , group_description(this, 3)
    , group_id(this, 4)
    , group_photo_uri(this, 5)
    , unique_id(this, 6)
    , activated(this, 7)
    , creator(this, _T("creator"))
// } AUTOGEN_END
{}

Group::Group(Yb::Session &session)
    : Yb::DomainObject(session.schema(), _T("group_tbl"))
// AUTOGEN_BEGIN(005) {
    , id(this, 0)
    , group_name(this, 2)
    , group_description(this, 3)
    , group_id(this, 4)
    , group_photo_uri(this, 5)
    , unique_id(this, 6)
    , activated(this, 7)
    , creator(this, _T("creator"))
// } AUTOGEN_END
{
// AUTOGEN_BEGIN(006) {
    set(7, Yb::Value(_T("DE-ACTIVATED")));
// } AUTOGEN_END
    save(session);
}

Group::Group(Yb::DataObject::Ptr d)
    : Yb::DomainObject(d)
// AUTOGEN_BEGIN(005) {
    , id(this, 0)
    , group_name(this, 2)
    , group_description(this, 3)
    , group_id(this, 4)
    , group_photo_uri(this, 5)
    , unique_id(this, 6)
    , activated(this, 7)
    , creator(this, _T("creator"))
// } AUTOGEN_END
{}

Group::Group(Yb::Session &session, const Yb::Key &key)
    : Yb::DomainObject(session, key)
// AUTOGEN_BEGIN(005) {
    , id(this, 0)
    , group_name(this, 2)
    , group_description(this, 3)
    , group_id(this, 4)
    , group_photo_uri(this, 5)
    , unique_id(this, 6)
    , activated(this, 7)
    , creator(this, _T("creator"))
// } AUTOGEN_END
{}

Group::Group(Yb::Session &session, Yb::LongInt id)
    : Yb::DomainObject(session, _T("group_tbl"), id)
// AUTOGEN_BEGIN(005) {
    , id(this, 0)
    , group_name(this, 2)
    , group_description(this, 3)
    , group_id(this, 4)
    , group_photo_uri(this, 5)
    , unique_id(this, 6)
    , activated(this, 7)
    , creator(this, _T("creator"))
// } AUTOGEN_END
{}

Group &Group::operator=(const Group &other)
{
    if (this != &other) {
        *(Yb::DomainObject *)this = (const Yb::DomainObject &)other;
    }
    return *this;
}

Group::ListPtr
Group::find(Yb::Session &session,
        const Yb::Expression &filter, const Yb::Expression &order_by)
{
    Group::ListPtr lst(new Group::List());
    Yb::ObjectList rows;
    session.load_collection(rows, Yb::Expression(_T("group_tbl")), filter, order_by);
    if (rows.size()) {
        Yb::ObjectList::iterator it = rows.begin(), end = rows.end();
        for (; it != end; ++it)
            lst->push_back(Group(*it));
    }
    return lst;
}

struct GroupRegistrator
{
    static void register_domain() {
        Yb::theDomainFactory().register_creator(_T("group_tbl"),
            Yb::CreatorPtr(new Yb::DomainCreator<Group>()));
    }
    GroupRegistrator() { register_domain(); }
};

static GroupRegistrator Group_registrator;

} // end namespace Domain

// vim:ts=4:sts=4:sw=4:et:
