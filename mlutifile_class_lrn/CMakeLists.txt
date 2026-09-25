cmake_minimum_required(VERSION 3.10)        #最低版本号
project(BoxTest)        #项目名
set(CMAKE_CXX_STANDARD 17)      #用c++11标准来编译
set(CMAKE_CXX_STANDARD_REQUIRED ON)     #强制要求编译器支持
add_executable(box_app mltf_class.cpp Box.cpp)      #可执行文件名,源文件1,2......