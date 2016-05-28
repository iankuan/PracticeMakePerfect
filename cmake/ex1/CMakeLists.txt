cmake_minimum_required(VERSION 3.0) #version required assign

project(ex1) #cmake Project
add_executable(ex1 main.c) #add executable file

message("hello")
set(var "cmake")
message(${var})

set(a alpha beta gamma)#string list, blankspace will be 
set(b "alpha beta gamma")#string
message("a = ${a}")#{} is needed not like bash script
message("b = ${b}")
