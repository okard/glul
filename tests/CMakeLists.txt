


# Simple test app
ADD_EXECUTABLE(simple_test simple_test.cpp)
TARGET_LINK_LIBRARIES(simple_test glul)

# Simple gl test app
ADD_EXECUTABLE(simple_gl_test simple_gl_test.cpp)
TARGET_LINK_LIBRARIES(simple_gl_test glul)

# Simple glew test app
ADD_EXECUTABLE(glew_test glew_test.cpp)
TARGET_LINK_LIBRARIES(glew_test glul)

# event test app
ADD_EXECUTABLE(event_test event_test.cpp)
TARGET_LINK_LIBRARIES(event_test glul)