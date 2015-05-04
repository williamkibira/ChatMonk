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

#include "../protobuffer/chat_monk.pb.h"
#include "models/invitation.h"
#include "grouphandler.h"
#include <string>
#include <list>


#ifndef INVITATIONHANDLER_H
#define INVITATIONHANDLER_H

class InvitationHandler
{
public:
InvitationHandler();
~InvitationHandler();
bool saveInvitation(protobuffer::InvitationDef *invitation);
Invitation getInvitationByID(std::string invitationID);
std::list<Invitation> getAllInvitations();
bool deleteInvitation(std::string invitationID);

private:
GroupHandler *grouphandler;
DataHandler *dataHandler;
Sar_Dbi *Sar_Dbi::sbi;
};

#endif // INVITATIONHANDLER_H
