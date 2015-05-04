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

FriendHandler::FriendHandler()
{
 datahandler = DataHandler::getInstance();
 Sar_Dbi::dbi = datahandler->getDBSar();
  
}
std::list< Friend > FriendHandler::getAllFriends()
{
  
  std::list<Friend> friends;
  
  ObjGroup<Friend> friendsDB = Friend::all();
  for(int i=0; i < friendsDB.size();++i){
    friends.push_back(friendsDB.at(i));
  }
  return friends;
  
}
Friend FriendHandler::getFriendByID(string friendID)
{
  Friend friendDB;
   friendDB.get("friend_id",friendID);
  return friendDB;
}
std::list< Friend > FriendHandler::getFriendByName(string name)
{
  std::list<Friend> friends;
  ObjGroup<Friend> friendsDB = Friend::find(Q("first_name",name)||Q("last_name",name));
  for(int i=0; i < friendsDB.size();++i){
    friends.push_back(friendsDB.at(i));
  }
  return friends;
}
bool FriendHandler::removeFriend(Friend* friendDB)
{
   Friend friendDel;
   friendDel.get("friend_id",friendDB->friend_id);
   friendDel.del();
   return true;
}
bool FriendHandler::removeFriend(string friendID){

   Friend friendDel;
   friendDel.get("friend_id",friendID);
   friendDel.del();
   return true;
}
bool FriendHandler::saveFriend(protobuffer::FriendDef* friendDef)
{
    Friend friendDB;
    friendDB.first_name = friendDef->first_name();
    friendDB.last_name = friendDef->last_name();
    friendDB.email = friendDef->email();
    friendDB.phone_number = friendDef->phone_number();
    friendDB.image_url = friendDef->photo_uri();
    friendDB.save();
}

FriendHandler::~FriendHandler()
{
  delete Sar_Dbi::dbi;
}
