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

#include "models/Friend.h"
#include "../protobuffer/chat_monk.pb.h"
#include <string>
#ifndef FRIENDHANDLER_H
#define FRIENDHANDLER_H
class FriendHandler
{
public:
FriendHandler(const Session& session);
~FriendHandler();
bool saveFriend(const protobuffer::FriendDef& friendDef);
Friend getFriendByID(std::string friendID);
DomainResultSet<Friend> getAllFriends();
bool removeFriend(std::string friendID);
bool removeFriend(Friend *friendDB);
DomainResultSet<Friend> getFriendByName(std::string name);
private:
Session session;

};

#endif // FRIENDHANDLER_H
