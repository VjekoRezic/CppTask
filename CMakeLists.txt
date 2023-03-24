cmake_minimum_required(VERSION 3.24)
project(FirstTask)

set(CMAKE_CXX_STANDARD 17)

add_executable(FirstTask main.cpp I_Printable.cpp I_Printable.h Book.cpp Book.h Loan.cpp Loan.h)
