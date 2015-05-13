add_subdirectory(models)
set(DATA_HANDLER_SOURCES datahandler.cpp friendhandler.cpp grouphandler.cpp invitationhandler.cpp messagehandler.cpp)

add_library(DATA_HANDLERS ${DATA_HANDLER_SOURCES})
