cmake_minimum_required(VERSION 3.31)
project(svd-parser VERSION 1.0 LANGUAGES CXX)

add_subdirectory(src bin)

target_include_directories(svd-parser PRIVATE include)

target_compile_features(svd-parser PRIVATE cxx_std_20)

target_compile_definitions(svd-parser PRIVATE
        $<$<CONFIG:Debug>:DEBUG=1>
        $<$<CONFIG:Release>:DEBUG=0>
)
