include_directories(${PROJECT_SOURCE_DIR})
include_directories(/usr/local/lib)
add_executable(${PROJECT_NAME}
    app.cpp
)
target_link_libraries(${PROJECT_NAME}
	PRIVATE ${OpenCV_LIBS}
	PRIVATE ${Boost_LIBRARIES}
)