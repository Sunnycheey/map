//
// Created by 12295 on 2022/12/24.
//

#ifndef HASHMAP_LINKEDLIST_H
#define HASHMAP_LINKEDLIST_H

#include "List.h"
template<typename T>
class LinkedNode {
public:
    LinkedNode(): _next(nullptr), _prev(nullptr) {}
    LinkedNode(T t): _data(t), _next(nullptr), _prev(nullptr) {}
    LinkedNode(T t, LinkedNode<T>* prev): _data(t), _prev(prev), _next(nullptr) {}
    T _data;
    LinkedNode* _next;
    LinkedNode* _prev;
};


template<typename T>
class LinkedList: public List<T> {
public:
    class Iterator {
    public:
    Iterator(): _cur(nullptr), _head(nullptr), _tail(nullptr) {}
    Iterator(LinkedList<T>* l): _cur(l->_head), _head(l->_head), _tail(l->_tail) {}
    T next() {
        _cur = _cur->_next;
        T data = _cur->_data;
        return data;
    }
    bool hasNext() {
        return _cur != _tail && (_cur != nullptr);
    }
    bool remove() {
        // remove current position
        if (_cur == nullptr || _cur == _head || _cur == _tail) {
            return false;
        }
        _cur->_prev->_next = _cur->_next;
        _cur->_next->_prev = _cur->_prev;
        delete _cur;
        return true;
    }
private:
    LinkedNode<T>* _cur;
    LinkedNode<T>* _head;
    LinkedNode<T>* _tail;
    };
    Iterator* getIterator() {
        return new Iterator(this);
    }
    void push_back(T t);
    T pop_back();
    T front();
    T back();
    LinkedList(): _head(new LinkedNode<T>()), _tail(new LinkedNode<T>()) {
        _head->_next = _tail;
        _tail->_prev = _head;
        _head->_prev = _tail;
        _tail->_next = _head;
    }
private:
    LinkedNode<T>* _head;
    LinkedNode<T>* _tail;
};

template<typename T>
void LinkedList<T>::push_back(T t) {
    auto* node = new LinkedNode<T>(t);
    _tail->_prev->_next = node;
    node->_prev = _tail->_prev;
    node->_next = _tail;
    _tail->_prev = node;
}

template<typename T>
T LinkedList<T>::pop_back() {
    T t;
    if (_tail->_prev != _head) {
        T data = _tail->_prev->_data;
        _tail->_prev = _tail->_prev->_prev;
        delete _tail->_prev->_next;
        _tail->_prev->_next = _tail;
        return data;
    }
    return t;
}

template<typename T>
T LinkedList<T>::front() {
    T t;
    if (_head->_next != _tail) {
        return _head->_next->_data;
    }
    return t;
}

template<typename T>
T LinkedList<T>::back() {
    T t;
    if (_tail->_prev != _head) {
        return _tail->_prev->_data;
    }
    return t;
}


#endif //HASHMAP_LINKEDLIST_H
