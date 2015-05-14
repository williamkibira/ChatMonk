#ifndef ORM_DOMAIN__FRIEND__INCLUDED
#define ORM_DOMAIN__FRIEND__INCLUDED

#include <yb/orm/domain_object.h>
// AUTOGEN_BEGIN(001) {
// } AUTOGEN_END

namespace Domain {

// AUTOGEN_BEGIN(002) {
class Group;
typedef Yb::DomainObjHolder<Group> GroupHolder;
// } AUTOGEN_END

class Friend;
typedef Yb::DomainObjHolder<Friend> FriendHolder;

class Friend: public Yb::DomainObject
{
public:
    typedef Yb::DomainObjHolder<Friend> Holder;
// AUTOGEN_BEGIN(007) {
    struct Columns {
        Yb::Column id, first_name, last_name, email, phone_number, photo_url, friend_id;
        Columns();
        void fill_table(Yb::Table &tbl);
    };
    static Columns c;
// } AUTOGEN_END
    static const Yb::String get_table_name() { return _T("friend_tbl"); }
    typedef Yb::DomainResultSet<Friend> ResultSet;
    // static method 'find'
    typedef std::vector<Friend> List;
    typedef std::auto_ptr<List> ListPtr;
    static ListPtr find(Yb::Session &session,
            const Yb::Expression &filter, const Yb::Expression &order_by = Yb::Expression());
    // constructors
    Friend(Yb::DomainObject *owner, const Yb::String &prop_name);
    Friend();
    Friend(const Friend &other);
    explicit Friend(Yb::Session &session);
    explicit Friend(Yb::DataObject::Ptr d);
    Friend(Yb::Session &session, const Yb::Key &key);
    Friend(Yb::Session &session, Yb::LongInt id);
    Friend &operator=(const Friend &other);
    static void create_tables_meta(Yb::Tables &tbls);
    static void create_relations_meta(Yb::Relations &rels);
// AUTOGEN_BEGIN(003) {
    // properties
    Yb::Property<Yb::LongInt> id;
    Yb::Property<Yb::String> first_name;
    Yb::Property<Yb::String> last_name;
    Yb::Property<Yb::String> email;
    Yb::Property<Yb::String> phone_number;
    Yb::Property<Yb::String> photo_url;
    Yb::Property<Yb::String> friend_id;
    // relation properties
    Yb::ManagedList<Group> groups;
// } AUTOGEN_END
};

} // namespace Domain

// vim:ts=4:sts=4:sw=4:et:
#endif
