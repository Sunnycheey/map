//
// Created by 12295 on 2022/12/24.
//

#ifndef HASHMAP_STDHASHFUNC_H
#define HASHMAP_STDHASHFUNC_H
#include "HashFunc.h"

template<typename T>
class StdHashFunc : public HashFunc<T>{
public:
    std::size_t getHash(T t) override {
        return _hashFunc(t);
    }
private:
    std::hash<T> _hashFunc;
};


#endif //HASHMAP_STDHASHFUNC_H
