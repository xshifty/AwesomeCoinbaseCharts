cmake_minimum_required (VERSION 3.8)

project (
	AwesomeCoinbaseCharts
	VERSION 1.0
	LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 20)
find_package(Boost 1.84.0 REQUIRED)

if(WIN32)
	add_executable (AwesomeCoinbaseCharts WIN32
			main.cpp
			acc/Bootstrap.h
			acc/Bootstrap.cpp
			acc/data/Bucket.cpp
			acc/data/Bucket.h)
else()
	add_executable (AwesomeCoinbaseCharts
			main.cpp
			acc/Bootstrap.h
			acc/Bootstrap.cpp
			acc/data/Bucket.cpp
			acc/data/Bucket.h)
endif()

include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(AwesomeCoinbaseCharts ${Boost_LIBRARIES})