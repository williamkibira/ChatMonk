cmake_minimum_required(VERSION 2.6)
project(chatmonk)

add_executable(chatmonk main.cpp)

install(TARGETS chatmonk RUNTIME DESTINATION bin)
include_directories(amqpcpp/include/)
include_directories(amqpcpp/src/)
add_subdirectory(views)
add_subdirectory(datahandlers)
add_subdirectory(broker)
add_subdirectory(network_handler)
add_subdirectory(protobuffer)

target_link_libraries(chatmonk  protobuf curl cdk ncurses stactiverecord amqpcpp rabbitmq ybutil yborm)
target_link_libraries(chatmonk PROTOBUFFER NETWORK_HANDLER DATA_HANDLERS)
add_subdirectory(table_schemas)