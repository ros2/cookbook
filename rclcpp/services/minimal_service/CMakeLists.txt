cmake_minimum_required(VERSION 3.5)
project(minimal_service)
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
if (NOT WIN32)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra")
endif()

rosidl_generate_interfaces(${PROJECT_NAME} "srv/AddTwoInts.srv")

add_executable(addition_server_lambda addition_server_lambda.cpp)

get_default_rmw_implementation(rmw_implementation)
find_package("${rmw_implementation}" REQUIRED)

get_rmw_typesupport(typesupport_impls "${rmw_implementation}" LANGUAGE "cpp")
foreach(typesupport_impl ${typesupport_impls})
  rosidl_target_interfaces(addition_server_lambda ${PROJECT_NAME} ${typesupport_impl})
endforeach()

ament_target_dependencies(addition_server_lambda rclcpp)

install(TARGETS addition_server_lambda
        DESTINATION bin)

ament_package()
