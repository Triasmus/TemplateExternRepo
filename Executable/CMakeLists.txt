set(exe_name Executable)

set(${exe_name}_deps ProtoFiles)

set(${exe_name}_srcs
  main.cpp
  )

source_group("" FILES ${${exe_name}_srcs})

add_executable(${exe_name} ${${exe_name}_srcs})
MESSAGE(STATUS "Deps: " ${${exe_name}_deps})
target_link_libraries(${exe_name} ${${exe_name}_deps})
install(TARGETS ${exe_name} DESTINATION bin)
