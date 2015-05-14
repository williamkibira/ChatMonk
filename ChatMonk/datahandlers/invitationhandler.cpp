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

InvitationHandler::InvitationHandler(Engine* engine)
{
  this->engine = engine;
}
bool InvitationHandler::deleteInvitation(std::string invitationID)
{
  Yb::Session session(Yb::init_schema(), engine);
  Invitation invitation = query<Invitation>(session).filter_by(Invitation::c.unique_id==invitationID).one();
  invitation.delete_object();
  session.commit();
  return true;
}
DomainResultSet<Invitation> InvitationHandler::getAllInvitations()
{
  Yb::Session session(Yb::init_schema(), engine);
  DomainResultSet<Invitation> invitations = query<Invitation>(session).all();
 
  return invitations;
}
Invitation InvitationHandler::getInvitationByID(std::string invitationID)
{
  Yb::Session session(Yb::init_schema(), engine);
  Invitation invitation = query<Invitation>(session).filter_by(Invitation::c.unique_id==invitationID).one();
  return invitation;
}
bool InvitationHandler::saveInvitation(const protobuffer::InvitationDef& invitation)
{
  Yb::Session session(Yb::init_schema(), engine);
  grouphandler = new GroupHandler(engine);
  Invitation::Holder invitationDB(session);
  invitationDB->unique_id = invitation.unique_id();
  invitationDB->private_message = invitation.personal_message();
  grouphandler->saveGroup(invitation.group());
  Group group = grouphandler->getGroupByID(invitation.group().group_id());
  group.activated = "FALSE";
  group.save(session);
  //invitationDB->sent_group = group;
  invitationDB->save(session);
  session.commit();
  return true;
}

InvitationHandler::~InvitationHandler()
{
  
}
