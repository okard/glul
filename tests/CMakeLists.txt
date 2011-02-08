


# Simple test app
ADD_EXECUTABLE(simple_test tests/simple_test.cpp)
TARGET_LINK_LIBRARIES(simple_test glul)

# Simple gl test app
ADD_EXECUTABLE(simple_gl_test tests/simple_gl_test.cpp)
TARGET_LINK_LIBRARIES(simple_gl_test glul)

# Simple glew test app
ADD_EXECUTABLE(glew_test tests/glew_test.cpp)
TARGET_LINK_LIBRARIES(glew_test glul)