cmake_minimum_required(VERSION 3.25)
project(OrderedItem)

set(CMAKE_CXX_STANDARD 17)

add_executable(OrderedItem main.cpp OrderItem.cpp OrderItem.h Customer.h Order.h Item.h Product.h Service.h)
