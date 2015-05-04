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

#include "invitationhandler.h"

InvitationHandler::InvitationHandler()
{
  dataHandler = DataHandler::getInstance();
  Sar_Dbi::dbi = dataHandler->getDBSar();
}
bool InvitationHandler::deleteInvitation(string invitationID)
{
  Invitation invitation;
  invitation.get("unique_id", invitationID);
  invitation.del();
  return true;
}
list< Invitation > InvitationHandler::getAllInvitations()
{
  std::list<Invitation> invitations;
  ObjGroup<Invitation> invites = Invitation::all();
  for(int i = 0; i < invites.size(); ++i){
    invitations.push_back(invites.at(i));
  }
  return invitations;
}
Invitation InvitationHandler::getInvitationByID(string invitationID)
{
  Invitation invitation;
  invitation.get("unique_id", invitationID);
  return invitation;
}
bool InvitationHandler::saveInvitation(protobuffer::InvitationDef* invitation)
{
  grouphandler = new GroupHandler();
  Invitation invitationDB;
  invitationDB.unique_id = invitation->unique_id();
  invitationDB.private_message = invitation->personal_message();
  grouphandler->saveGroup(invitation->group());
  Group group = grouphandler->getGroupByID(invitation->group().group_id());
  group.activated = false;
  group.update();
  invitationDB.group = group;
  invitationDB.save();
  return invitationDB.has_been_saved();
}

InvitationHandler::~InvitationHandler()
{
  delete Sar_Dbi::dbi;
}
