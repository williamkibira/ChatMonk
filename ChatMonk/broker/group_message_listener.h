#ifndef GROUP_MSG_LISTENER_H
#define GROUP_MSG_LISTENER_H
#include "../protobuffer/chat_monk.pb.h"
class GroupMessageListener{
public:
  virtual void messageGroupReceived(const protobuffer::Message&, size_t)=0;
  
  
};

#endif // GROUP_MSG_LISTENER_H