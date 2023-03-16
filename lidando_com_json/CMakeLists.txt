cmake_minimum_required(VERSION 3.5)
project("lidando json" VERSION 0.1 LANGUAGES CXX )

# set the compiling flags
set ( CMAKE_CXX_FLAGS "-Wall -g"  )
#set( CMAKE_LD_FLAGS "-L/opt/local/lib" ) # was for boost
set(CMAKE_LD_FLAGS "-L/usr/include/curl/lib -lcurl")
#set(CMAKE_LD_FLAGS "-ljsoncpp")


#--------------------------------
# This is for old cmake versions
#set (CMAKE_CXX_STANDARD 11)
#--------------------------------

### [1] Application target
# configura o diretório contendo os .h, assim você pode incluílos apenas com include "arquivo.h"
include_directories( include )
include_directories(/usr/include)
include_directories(/usr/include/boost)
include_directories(/usr/include/curl/lib)
include_directories(/usr/include/json)

### [2] Test engine
# includes do test manager
include_directories( test_manager/include )

set ( EXEC_NAME "lidando_json")

# Cria um executável com nome "run_tests", adiciona neste executável os arquivos do test manager e o seu main.cpp

add_executable( ${EXEC_NAME}
                src/main.cpp

                )

# define C++14 standard
set_property(TARGET ${EXEC_NAME} PROPERTY CXX_STANDARD 14)



add_custom_target(
    verify
    COMMAND python3 ${CMAKE_SOURCE_DIR}/../scripts/verify-inputs.py ./${EXEC_NAME}
    DEPENDS ${EXEC_NAME}
)




# The end
