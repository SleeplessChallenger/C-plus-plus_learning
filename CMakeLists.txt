cmake_minimum_required(VERSION 3.25)
project(LearningC__)

set(CMAKE_CXX_STANDARD 14)

include_directories(nineth_task)

add_executable(C-plus-plus_learning main.cpp first_task/constant_challenge.cpp second_task/containers_challenge.cpp third_task/operators_challenge.cpp fourth_task/calculator_challenge.cpp fifth_task/elements_challenge.cpp sixth_task/cipher_challenge.cpp sixth_task/pyramid_challenge.cpp seventh_task/functions_challenge.cpp eighth_task/pointers_challenge.cpp nineth_task/Movie.h nineth_task/Movies.h tenth_task/CustomString.cpp nineth_task/Movie.cpp nineth_task/Movies.cpp eleventh_task/AccountChallenge.cpp eleventh_task/AccountUtils.cpp eleventh_task/CheckingAccount.cpp eleventh_task/SavingsAccountChallenge.cpp eleventh_task/TrustAccount.cpp)