cmake_minimum_required(VERSION 2.8.3)
project(metis_ros)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS
 roscpp 
 rospy 
 std_msgs 
 message_generation
 tf
)

## Generate added messages and services
add_service_files(FILES strings.srv)
generate_messages(DEPENDENCIES std_msgs)



## Declare a catkin package
catkin_package()
##catkin_python_setup()

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})




add_executable(talker src/talker.cpp)
target_link_libraries(talker ${catkin_LIBRARIES})
add_dependencies(talker metis_ros_generate_messages_cpp)


add_executable(Sentiment src/Sentiment.cpp)
target_link_libraries(Sentiment ${catkin_LIBRARIES})
add_dependencies( Sentiment  metis_ros_generate_messages_cpp)



add_executable(PositiveSentiment src/PositiveSentiment.cpp)
target_link_libraries(PositiveSentiment ${catkin_LIBRARIES})
add_dependencies( PositiveSentiment  metis_ros_generate_messages_cpp)


add_executable(NegativeSentiment src/NegativeSentiment.cpp)
target_link_libraries(NegativeSentiment ${catkin_LIBRARIES})
add_dependencies( NegativeSentiment  metis_ros_generate_messages_cpp)


add_executable(Parser src/Parser.cpp)
target_link_libraries(Parser ${catkin_LIBRARIES})
add_dependencies( Parser  metis_ros_generate_messages_cpp)


add_executable(main src/main.cpp)
target_link_libraries(main ${catkin_LIBRARIES})
add_dependencies( main  metis_ros_generate_messages_cpp)
#add_executable( main.cpp Parser.cpp 
# Sentiment.cpp
# PositiveSentiment.cpp
# NegativeSentiment.cpp
#)


add_executable(listener src/listener.cpp)
target_link_libraries(listener ${catkin_LIBRARIES})
add_dependencies(listener metis_ros_generate_messages_cpp)



catkin_install_python(PROGRAMS
scripts/voice_ros.py
DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})



if(CATKIN_ENABLE_TESTING)
  find_package(rostest REQUIRED)
  
  add_rostest_gtest(
          talker_test
	  test/talker_test.launch
	  test/talker_test.cpp
  )
  
  target_link_libraries(
	  talker_test
	  ${catkin_LIBRARIES}
  )
  
  add_dependencies(
	  talker
	  talker_test
	  ${catkin_EXPORTED_TARGETS}
          ${PROJECT_NAME}_generate_messages_cpp

  )
endif()




