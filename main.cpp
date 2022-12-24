#include <iostream>
#include "HashMap.h"
#include "iostream"

int main() {
    Map<int, int> *hashMap = new HashMap<int, int>(720);\

    hashMap->put(2, 3);
    std::cout << hashMap->get(2) << std::endl;
    hashMap->put(2, 4);
    std::cout << hashMap->get(2) << std::endl;
//    for(int i = 0; i < 10000; i++) {
//        hashMap->put(i, i);
//    }
//    for(int i = 0; i < 10000; i++) {
//        std::cout << hashMap->get(i) << std::endl;
//    }
//
//    for(int i = 0; i < 10000; i++) {
//        hashMap->remove(i);
//    }
//
//    std:: cout << "After remove" << std::endl;
//    for(int i = 0; i < 10000; i++) {
//        std::cout << hashMap->get(i) << std::endl;
//    }
//    Map<std::string, std::string> *strMap = new Map<std::string, std::string>(1440);
//    for(int i = 0; i < 10000; i++) {
//        strMap->put(std::to_string(i), std::to_string(i));
//    }
//    for(int i = 0; i < 10000; i++) {
//        std::cout << strMap->get(std::to_string(i)) << std::endl;
//    }
//    for (int i = 0; i < 10000; i++) {
//        strMap->remove(std::to_string(i));
//    }
//    std:: cout << "After remove" << std::endl;
//    for(int i = 0; i < 10000; i++) {
//        std::cout << strMap->get(std::to_string(i)) << std::endl;
//    }
}
