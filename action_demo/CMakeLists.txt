cmake_minimum_required(VERSION 3.8)
project(action_demo)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()


if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()


# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

find_package(geometry_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(rclcpp_components REQUIRED)

include_directories(include)

add_library(action_demo SHARED
  src/fibonacci_action_client.cpp
  src/fibonacci_action_server.cpp)
rclcpp_components_register_node(action_demo PLUGIN "action_demo::FibonacciActionClient" EXECUTABLE fibonacci_action_client)
rclcpp_components_register_node(action_demo PLUGIN "action_demo::FibonacciActionServer" EXECUTABLE fibonacci_action_server)
target_compile_definitions(action_demo
  PRIVATE "ACTION_DEMO_CPP_BUILDING_DLL")
ament_target_dependencies(action_demo
  "rclcpp"
  "rclcpp_action"
  "rclcpp_components")

install(TARGETS
  action_demo
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)



if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()


# Install Python modules
ament_python_install_package(${PROJECT_NAME})
 
# Install Python executables
install(PROGRAMS
  action_demo/fibonacci_action_client.py
  action_demo/fibonacci_action_server.py
  DESTINATION lib/${PROJECT_NAME}
)


ament_package()
