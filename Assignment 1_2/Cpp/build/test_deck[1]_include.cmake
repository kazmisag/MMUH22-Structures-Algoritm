if(EXISTS "/home/kazmisag/Documents/ECutbildining SW Developer/Data Structrued and Algo/MMUH22-Structures-Algoritm/Assignment 1_2/Cpp/build/test_deck[1]_tests.cmake")
  include("/home/kazmisag/Documents/ECutbildining SW Developer/Data Structrued and Algo/MMUH22-Structures-Algoritm/Assignment 1_2/Cpp/build/test_deck[1]_tests.cmake")
else()
  add_test(test_deck_NOT_BUILT test_deck_NOT_BUILT)
endif()