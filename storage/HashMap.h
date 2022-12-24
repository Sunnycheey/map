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
    void put(K k, V v) override;
    V get(K k) override;
    bool remove(K k) override;
    size_t size() override;
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

template<typename K, typename V, typename HashFunc>
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

template<typename K, typename V, typename HashFunc>
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

template<typename K, typename V, typename HashFunc>
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
            return _list[bucketIdx]->remove(iterator);
        }
    }
    return false;
}

template<typename K, typename V, typename HashFunc>
size_t HashMap<K, V, HashFunc>::size() {
    size_t s = 0;
    for (int i = 0; i < this->_bucketSize; i++) {
        if (_list[i] == nullptr) {
            return 0;
        }
        s += _list[i]->getSize();
    }
    return s;
}


#endif //HASHMAP_HASHMAP_H
