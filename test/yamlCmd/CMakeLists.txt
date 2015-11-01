add_executable(yamlCmdTest yamlCmdTest.cpp)
target_link_libraries(yamlCmdTest ${CMAKE_SOURCE_DIR}/ext/yaml-cpp/libyaml-cpp.a)