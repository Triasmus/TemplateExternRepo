set(exe_name Playground)
########################################
# External Libraries
xpGetExtern(externIncs externLibs PUBLIC boost)
########################################
set(${exe_name}_srcs
  main.cpp
  )

source_group("" FILES ${${exe_name}_srcs})


add_executable(${exe_name} ${${exe_name}_srcs})
MESSAGE(STATUS "boost: " ${externLibs})
MESSAGE(STATUS "boost: " ${externIncs})
target_link_libraries(${exe_name} PUBLIC ${externLibs})
target_include_directories(${exe_name} PUBLIC ${externIncs})
set_property(TARGET ${exe_name} PROPERTY FOLDER ${folder})

install(TARGETS ${exe_name} DESTINATION bin)
