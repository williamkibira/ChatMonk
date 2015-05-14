#include "datahandlers/datahandler.h"
#ifndef GROUP_CHAT_H
#define GROUP_CHAT_H

class GroupChatView{
	
public:
GroupChatView(WINDOW *topWindow);
virtual ~GroupChatView();
private:
DataHandler *dbHandler;
GroupHandler *grpHandler;	
MessageHandler *msgHandler;

};


#endif // GROUP_CHAT_H