//
// Created by paa04 on 03.05.2024.
//

#ifndef LAB_02_LIST_ITERATOR_H
#define LAB_02_LIST_ITERATOR_H

#include <memory>
#include "list_node.h"
#include "base_iterator.h"

template<succeed_type T>
class list_iterator: public BaseIterator<T>
{
public:
    list_iterator();

    explicit list_iterator(const std::shared_ptr<list_node<T>> &ptr);

    list_iterator(const list_iterator<T> &iterator);

    ~list_iterator() = default;

    std::shared_ptr<list_node<T>> get_node();

    void next();

    explicit operator bool() const;

    list_iterator<T>& operator=(const list_iterator<T> &listIterator);

    list_iterator<T>& operator=(list_iterator<T> &&listIterator) noexcept;

    T& operator*() const;

    T* operator->() const;

    list_iterator<T>& operator++();

    list_iterator<T> operator++(int);

    list_iterator<T> operator+ (int size) const;

    list_iterator<T>& operator+=(int size);

    bool is_valid() const;

    bool operator==(const list_iterator<T> &it) const;

    bool operator!=(const list_iterator<T> &it) const;
};

#include "list_iterator.hpp"

#endif //LAB_02_LIST_ITERATOR_H
