#ifndef FRIEND_MSG_LISTENER_H
#define FRIEND_MSG_LISTENER_H
#include "../protobuffer/chat_monk.pb.h"
class FriendMessageListener{
public:
   virtual void messageFriendReceived(const protobuffer::Message& , size_t)=0;
};

#endif // FRIEND_MSG_LISTENER_H