#ifndef INVITATION_MSG_LISTENER_H
#define INVITATION_MSG_LISTENER_H
#include "../protobuffer/chat_monk.pb.h"
class InvitationMessageHandler{
  
public:
   virtual void invitationMessageReceived(const protobuffer::InvitationDef&, size_t)=0;
   
};

#endif // INVITATION_MSG_LISTENER_H