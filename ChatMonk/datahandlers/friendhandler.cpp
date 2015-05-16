/*
 * Copyright 2015 <copyright holder> <email>
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 */

#include "friendhandler.h"

FriendHandler::FriendHandler(Engine* engine)
{
 this->engine = engine;
}

DomainResultSet<Friend> FriendHandler::getAllFriends()
{
   Yb::Session session(Yb::init_schema(), engine);

  DomainResultSet<Friend> friends = query<Friend>(session).all();
  
  return friends;
  
}
Friend FriendHandler::getFriendByID(std::string friendID)
{
  Yb::Session session(Yb::init_schema(), engine);
  Friend friendDB = query<Friend>(session).filter_by(Friend::c.friend_id==friendID).one();
  
  return friendDB;
}
DomainResultSet<Friend> FriendHandler::getFriendByName(std::string name)
{
  Yb::Session session(Yb::init_schema(), engine);
  DomainResultSet<Friend> friends = query<Friend>(session)
  .filter_by(Friend::c.first_name==name || Friend::c.last_name==name).all();
  
  return friends;
}
bool FriendHandler::removeFriend(Friend* friendDB)
{
   Yb::Session session(Yb::init_schema(), engine);
   Friend friendDel = query<Friend>(session)
   .filter_by(Friend::c.friend_id==friendDB->friend_id).one();
   friendDel.delete_object();
   session.commit();
   return true;
}
bool FriendHandler::removeFriend(std::string friendID){
   Yb::Session session(Yb::init_schema(), engine);
   Friend friendDel = query<Friend>(session).filter_by(Friend::c.friend_id==friendID).one();
   friendDel.delete_object();
   session.commit();
   return true;
}

bool FriendHandler::saveFriend(const protobuffer::FriendDef &friendDef)
{
    Yb::Session session(Yb::init_schema(), engine);
    Friend::Holder friendDB;
    friendDB->first_name = friendDef.first_name();
    friendDB->last_name = friendDef.last_name();
    friendDB->email = friendDef.email();
    friendDB->phone_number = friendDef.phone_number();
    friendDB->photo_url = friendDef.photo_uri();
    friendDB->save(session);
    
    return true;
    
}

FriendHandler::~FriendHandler()
{
  
}
