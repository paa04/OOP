//
// Created by paa04 on 23.04.24.
//

#ifndef CONST_ITERATOR_HPP
#define CONST_ITERATOR_HPP

#include "const_iterator.h"

template<typename T>
const_list_iterator<T>::const_list_iterator()
{
    this->ptr.lock() = nullptr;
}

template<typename T>
const_list_iterator<T>::const_list_iterator(const const_list_iterator<T> &iterator)
{
    this->ptr = iterator.ptr.lock();
}

template<typename T>
const_list_iterator<T>::const_list_iterator(const std::shared_ptr<list_node<T> > &node)
{
    this->ptr = node;
}

template<typename T>
void const_list_iterator<T>::next()
{
    this->ptr = ptr.lock()->get_next();
}

template<typename T>
const_list_iterator<T> &const_list_iterator<T>::operator++()
{
    this->next();
    return *this;
}

template<typename T>
const_list_iterator<T> const_list_iterator<T>::operator++(int)
{
    const_list_iterator tmp(*this);
    this->next();
    return tmp;
}

template<typename T>
bool const_list_iterator<T>::is_invalid() const
{
    return this->ptr.lock() == nullptr;
}

template<typename T>
const list_node<T> &const_list_iterator<T>::operator*() const
{
    return *this->ptr.lock().get();
}

template<typename T>
const_list_iterator<T>::operator bool() const
{
    return this->ptr.lock() == nullptr;
}

template<typename T>
const_list_iterator<T> const_list_iterator<T>::operator+(const int &size) const
{
    const_list_iterator tmp(*this);
    tmp += size;
    return tmp;
}

template<typename T>
const_list_iterator<T> &const_list_iterator<T>::operator+=(const int &size)
{
    for (int i = 0; i < size; ++i)
    {
        this->next();
    }

    return *this;
}

template <typename T>
const list_node<T> *const_list_iterator<T>::operator ->() const
{
    return this->ptr.lock().get();
}

template<typename T>
const_list_iterator<T> const_list_iterator<T>::operator=(const list_iterator<T> &iterator)
{
    this->ptr = iterator.ptr.lock();
    return *this;
}

template<typename T>
bool const_list_iterator<T>::operator!=(const const_list_iterator<T> &iterator) const
{
    return this->ptr.lock() != iterator.ptr.lock();
}

template<typename T>
bool const_list_iterator<T>::operator==(const const_list_iterator<T> &iterator) const
{
    return this->ptr.lock() == iterator.ptr.lock();
}


#endif //CONST_ITERATOR_HPP
