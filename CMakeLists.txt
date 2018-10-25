cmake_minimum_required(VERSION 3.0)

project(arrp-web-service)

add_subdirectory(server)

install(DIRECTORY arrp/ DESTINATION arrp)
