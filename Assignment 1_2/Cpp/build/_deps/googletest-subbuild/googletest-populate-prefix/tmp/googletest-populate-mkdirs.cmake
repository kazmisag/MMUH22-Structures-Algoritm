# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/kazmisag/Documents/ECutbildining SW Developer/Data Structrued and Algo/MMUH22-Structures-Algoritm/Assignment 1_2/Cpp/build/_deps/googletest-src"
  "/home/kazmisag/Documents/ECutbildining SW Developer/Data Structrued and Algo/MMUH22-Structures-Algoritm/Assignment 1_2/Cpp/build/_deps/googletest-build"
  "/home/kazmisag/Documents/ECutbildining SW Developer/Data Structrued and Algo/MMUH22-Structures-Algoritm/Assignment 1_2/Cpp/build/_deps/googletest-subbuild/googletest-populate-prefix"
  "/home/kazmisag/Documents/ECutbildining SW Developer/Data Structrued and Algo/MMUH22-Structures-Algoritm/Assignment 1_2/Cpp/build/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "/home/kazmisag/Documents/ECutbildining SW Developer/Data Structrued and Algo/MMUH22-Structures-Algoritm/Assignment 1_2/Cpp/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "/home/kazmisag/Documents/ECutbildining SW Developer/Data Structrued and Algo/MMUH22-Structures-Algoritm/Assignment 1_2/Cpp/build/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "/home/kazmisag/Documents/ECutbildining SW Developer/Data Structrued and Algo/MMUH22-Structures-Algoritm/Assignment 1_2/Cpp/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/kazmisag/Documents/ECutbildining SW Developer/Data Structrued and Algo/MMUH22-Structures-Algoritm/Assignment 1_2/Cpp/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/kazmisag/Documents/ECutbildining SW Developer/Data Structrued and Algo/MMUH22-Structures-Algoritm/Assignment 1_2/Cpp/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
