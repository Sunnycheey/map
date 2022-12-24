//
// Created by 12295 on 2022/12/24.
//

#ifndef HASHMAP_MAP_H
#define HASHMAP_MAP_H

#include <cstdint>
#include "StdHashFunc.h"
#include "KvData.h"
template<typename K, typename V, typename HashFunc=StdHashFunc<K>>
class Map {
public:
    virtual void put(K k, V v) = 0;
    virtual V get(K k) = 0;
    virtual bool remove(K k) = 0;
    Map(int32_t bucketSize): _bucketSize(bucketSize) {}
protected:
    int32_t _bucketSize;
};


#endif //HASHMAP_MAP_H
