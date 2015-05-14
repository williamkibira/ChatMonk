#ifndef ORM_DOMAIN__INVITATION__INCLUDED
#define ORM_DOMAIN__INVITATION__INCLUDED

#include <yb/orm/domain_object.h>
// AUTOGEN_BEGIN(001) {
#include "../domain/Group.h"
// } AUTOGEN_END

namespace Domain {

// AUTOGEN_BEGIN(002) {
// } AUTOGEN_END

class Invitation;
typedef Yb::DomainObjHolder<Invitation> InvitationHolder;

class Invitation: public Yb::DomainObject
{
public:
    typedef Yb::DomainObjHolder<Invitation> Holder;
// AUTOGEN_BEGIN(007) {
    struct Columns {
        Yb::Column id, group_id, private_message, unique_id;
        Columns();
        void fill_table(Yb::Table &tbl);
    };
    static Columns c;
// } AUTOGEN_END
    static const Yb::String get_table_name() { return _T("invitation_tbl"); }
    typedef Yb::DomainResultSet<Invitation> ResultSet;
    // static method 'find'
    typedef std::vector<Invitation> List;
    typedef std::auto_ptr<List> ListPtr;
    static ListPtr find(Yb::Session &session,
            const Yb::Expression &filter, const Yb::Expression &order_by = Yb::Expression());
    // constructors
    Invitation(Yb::DomainObject *owner, const Yb::String &prop_name);
    Invitation();
    Invitation(const Invitation &other);
    explicit Invitation(Yb::Session &session);
    explicit Invitation(Yb::DataObject::Ptr d);
    Invitation(Yb::Session &session, const Yb::Key &key);
    Invitation(Yb::Session &session, Yb::LongInt id);
    Invitation &operator=(const Invitation &other);
    static void create_tables_meta(Yb::Tables &tbls);
    static void create_relations_meta(Yb::Relations &rels);
// AUTOGEN_BEGIN(003) {
    // properties
    Yb::Property<Yb::LongInt> id;
    Yb::Property<Yb::String> private_message;
    Yb::Property<Yb::String> unique_id;
    // relation properties
// } AUTOGEN_END
};

} // namespace Domain

// vim:ts=4:sts=4:sw=4:et:
#endif
