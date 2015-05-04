cmake_minimum_required(VERSION 2.6)
project(chatmonk)

add_executable(chatmonk main.cpp broker/messageconsumer.cpp network_handler/networkhandler.cpp protobuffer/chat_monk.pb.cc 
datahandlers/models/chatmessage.cpp datahandlers/models/friend.cpp datahandlers/models/group.cpp datahandlers/models/invitation.cpp)
#datahandlers/datahandler.cpp datahandlers/friendhandler.cpp datahandlers/invitationhandler.cpp datahandlers/messagehandler.cpp 
#datahandlers/grouphandler.cpp datahandlers )

install(TARGETS chatmonk RUNTIME DESTINATION bin)
include_directories(amqpcpp/include/)
include_directories(amqpcpp/src/)
add_subdirectory(views)
add_subdirectory(datahandlers)
add_subdirectory(broker)
add_subdirectory(network_handler)
add_subdirectory(protobuffer)

target_link_libraries(chatmonk  protobuf curl cdk ncurses stactiverecord amqpcpp rabbitmq)