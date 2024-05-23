//
// Created by paa04 on 04.05.2024.
//

#ifndef LAB_02_CONST_LIST_ITERATOR_H
#define LAB_02_CONST_LIST_ITERATOR_H

#include <iterator>
#include <memory>
#include "list_node.h"

template<typename T>
class const_list_iterator
{
public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = T;

    const_list_iterator();

    explicit const_list_iterator(const std::shared_ptr<list_node<T>> &ptr);

    const_list_iterator(const const_list_iterator<T> &iterator);

    ~const_list_iterator() = default;

    std::shared_ptr<const list_node<T>> get_node() const;

    void next();

    explicit operator bool() const;

    bool is_valid() const;

    const_list_iterator<T>& operator=(const const_list_iterator<T> &listIterator);

    const_list_iterator<T>& operator=(const_list_iterator<T> &&listIterator) noexcept;

    const T& operator*() const;

    const T* operator->() const;

    const_list_iterator<T>& operator++();

    const_list_iterator<T> operator++(int);

    const_list_iterator<T> operator+ (int size) const;

    const_list_iterator<T>& operator+=(int size);

    bool operator==(const const_list_iterator<T>& iterator) const;

    bool operator!=(const const_list_iterator<T>& iterator) const;

private:
    std::weak_ptr<list_node<T>> ptr;
};


#include "const_list_iterator.hpp"

#endif //LAB_02_CONST_LIST_ITERATOR_H
