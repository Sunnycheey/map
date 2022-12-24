//
// Created by 12295 on 2022/12/24.
//

#ifndef HASHMAP_KVDATA_H
#define HASHMAP_KVDATA_H

template<typename K, typename V>
class KvData {
public:
    KvData(K k, V v): _key(k), _val(v) {}
    KvData() {}
    K getKey() {return _key;}
    V getVal() { return _val;}
private:
    K _key;
    V _val;
};


#endif //HASHMAP_KVDATA_H
