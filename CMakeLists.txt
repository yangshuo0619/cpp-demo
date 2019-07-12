cmake_minimum_required(VERSION 3.5)

project( demo1 )

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( usb_camera src/usb_camera.cpp )
add_executable( create_image src/create_image.cpp )
target_link_libraries( usb_camera ${OpenCV_LIBS} )
target_link_libraries( create_image ${OpenCV_LIBS} )
