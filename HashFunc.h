//
// Created by 12295 on 2022/12/24.
//

#ifndef HASHMAP_HASHFUNC_H
#define HASHMAP_HASHFUNC_H

#include <string>
#include <functional>

template<typename T>
class HashFunc {
public:
    virtual std::size_t getHash(T t);
};


#endif //HASHMAP_HASHFUNC_H
