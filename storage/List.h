//
// Created by 12295 on 2022/12/24.
//

#ifndef HASHMAP_LIST_H
#define HASHMAP_LIST_H

template <typename T>
class List {
public:
    virtual void push_back(T t) = 0;
    virtual T pop_back() = 0;
    virtual T back() = 0;
    virtual T front() = 0;
};


#endif //HASHMAP_LIST_H
