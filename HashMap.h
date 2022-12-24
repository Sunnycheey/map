//
// Created by 12295 on 2022/12/24.
//

#ifndef HASHMAP_HASHMAP_H
#define HASHMAP_HASHMAP_H

#include <cstdint>
#include "Map.h"
#include "List.h"
#include "LinkedList.h"
#include "HashFunc.h"

template<typename K, typename V, typename HashFunc=StdHashFunc<K>>
class HashMap : public Map<K, V, HashFunc> {
    typedef KvData<K, V> KV;
public:
    void put(K k, V v);
    V get(K k);
    bool remove(K k);
    HashMap(int32_t bucketSize): Map<K, V, HashFunc>(bucketSize), _list(new LinkedList<KV>*[bucketSize]) {
        for (int i = 0; i < bucketSize; i++) {
            _list[i] = new LinkedList<KV>();
        }
    }
    ~HashMap() {
        for(int i = 0; i < this->_bucketSize; i++) {
            delete _list[i];
        }
        delete []_list;
    }

private:
    LinkedList<KV>** _list;
};

template<typename K, typename V, class HashFunc>
void HashMap<K, V, HashFunc>::put(K k, V v) {
    HashFunc hashFunc;
    this->remove(k);
    std::size_t slot = hashFunc.getHash(k);
    int32_t bucketIdx = slot % this->_bucketSize;
    if (_list[bucketIdx] == nullptr) {
        return;
    }
    KV kvData(k, v);
    _list[bucketIdx]->push_back(kvData);
}

template<typename K, typename V, class HashFunc>
V HashMap<K, V, HashFunc>::get(K k) {
    V ret = V();
    HashFunc hashFunc;
    std::size_t slot = hashFunc.getHash(k);
    int32_t bucketIdx = slot % this->_bucketSize;
    if (_list[bucketIdx] == nullptr) {
        return ret;
    }
    auto* iterator = _list[bucketIdx]->getIterator();
    while(iterator->hasNext()) {
        KV kvData = iterator->next();
        if (kvData.getKey() == k) {
            return kvData.getVal();
        }
    }
    return ret;
}

template<typename K, typename V, class HashFunc>
bool HashMap<K, V, HashFunc>::remove(K k) {
    HashFunc hashFunc;
    std::size_t slot = hashFunc.getHash(k);
    int32_t bucketIdx = slot % this->_bucketSize;
    if (_list[bucketIdx] == nullptr) {
        return false;
    }
    auto* iterator = _list[bucketIdx]->getIterator();
    while(iterator->hasNext()) {
        KV kvData = iterator->next();
        if (kvData.getKey() == k) {
            return iterator->remove();
        }
    }
    return false;
}


#endif //HASHMAP_HASHMAP_H
