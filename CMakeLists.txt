cmake_minimum_required(VERSION 3.5)

# GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -Wpedantic)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address")

# Set the project name
project (LearningCpp)

# Add libs 
add_subdirectory(${CMAKE_SOURCE_DIR}/src/Advanced/Lambda)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/EffectiveC++)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/Advanced/options)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/Advanced/SmartPointers)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/Mastering4CriticalSkillsUsingC++17/OOP)

# Add executables
add_executable(app src/main.cpp)
add_executable(namespace src/Mastering4CriticalSkillsUsingC++17/namespaces/namespace.cpp)
add_executable(structures src/Mastering4CriticalSkillsUsingC++17/structures/structures_inheritance.cpp)
add_executable(exception src/Mastering4CriticalSkillsUsingC++17/exceptions/exceptions.cpp)
add_executable(noexcept src/Mastering4CriticalSkillsUsingC++17/exceptions/noexcept.cpp)
add_executable(mutex src/Multithreding/mutex.cpp)
add_executable(future src/Multithreding/future.cpp)

target_link_libraries( 
	app
  PUBLIC lambda
  PUBLIC options
	PUBLIC SmartPointers
	PUBLIC oop
	PUBLIC EffectiveCpp
	)
	
target_include_directories(
	app
	PUBLIC inc
	PUBLIC src/Advanced/Lambda
	PUBLIC src/Advanced/options
	PUBLIC src/Advanced/SmartPointers
	PUBLIC src/Mastering4CriticalSkillsUsingC++17/OOP
	PUBLIC src/EffectiveC++
	)


##! Gtest
include(FetchContent)
FetchContent_Declare(
	googletest
	URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
	)
	
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()
add_executable(lambda_test src/tests/Advanced/lambda_test.cpp)
target_link_libraries(
	lambda_test
	GTest::gtest_main
	)
include(GoogleTest)
gtest_discover_tests(lambda_test)