add_library(ml_mongodb SHARED module.cc)
target_link_libraries(ml_mongodb PRIVATE lua lua-mongo)

if(WIN32)
    target_compile_definitions(ml_mongodb PRIVATE WIN32_LEAN_AND_MEAN _CRT_SECURE_NO_WARNINGS)
endif()
