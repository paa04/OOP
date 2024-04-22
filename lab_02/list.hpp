//
// Created by paa04 on 15.04.24.
//

#ifndef LIST_HPP
#define LIST_HPP

#include <chrono>

#include "iterator.h"
#include "list.h"

template<typename T>
list<T>::list()
{
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

template<typename T>
list<T>::list(list<T> &&list)
{
    this->tail = list.tail;
    this->head = list.head;
    this->size = list.size;
}

template<typename T>
list_iterator<T> list<T>::push_back(const T &data)
{
    std::shared_ptr<list_node<T> > node = nullptr;

    try
    {
        node = std::shared_ptr<list_node<T> >(new list_node<T>);
    } catch (std::bad_alloc &error)
    {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw memory_error(ctime(&timenow), __FILE__, typeid(list).name(), __FUNCTION__);
    }

    node->set(data);
    return this->push_back(node);
}



template<typename T>
list<T>::list(list<T> &list)
{
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;

    for (auto node: list)
    {
        this->push_back(node);
    }
}


#endif //LIST_HPP
