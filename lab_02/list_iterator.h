//
// Created by paa04 on 03.05.2024.
//

#ifndef LAB_02_LIST_ITERATOR_H
#define LAB_02_LIST_ITERATOR_H

#include <iterator>
#include <memory>
#include "list_node.h"

template<typename T>
class list_iterator : std::iterator<std::input_iterator_tag, T>
{
public:
    list_iterator();

    explicit list_iterator(const std::shared_ptr<list_node<T>> &ptr);

    list_iterator(const list_iterator<T> &iterator);

    ~list_iterator() = default;

    void next();

    explicit operator bool() const;

    list_iterator<T>& operator=(const list_iterator<T> &listIterator);

    list_iterator<T>& operator=(list_iterator<T> &&listIterator) noexcept;

    list_node<T>& operator*() const;

    list_node<T>& operator->() const;

    list_iterator<T>& operator++();

    list_iterator<T> operator++(int);

    list_iterator<T> operator+ (int size) const;

    list_iterator<T>& operator+=(int size);

    bool operator==(const list_iterator<T>& iterator);

    bool operator!=(const list_iterator<T>& iterator);

private:
    std::weak_ptr<list_node<T>> ptr;
};

#include "list_iterator.hpp"

#endif //LAB_02_LIST_ITERATOR_H