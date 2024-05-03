//
// Created by paa04 on 03.05.2024.
//

#ifndef LAB_02_LIST_ITERATOR_HPP
#define LAB_02_LIST_ITERATOR_HPP

template<typename T>
list_iterator<T>::list_iterator()
{
    this->ptr.lock() = nullptr;
}

template<typename T>
list_iterator<T>::list_iterator(const std::shared_ptr<list_node<T>> &ptr)
{
    this->ptr = std::weak_ptr(ptr);
}

template<typename T>
list_iterator<T>::list_iterator(const list_iterator<T> &iterator)
{
    this->ptr = iterator.ptr;
}

template<typename T>
void list_iterator<T>::next()
{
    this->ptr = this->ptr.lock()->get_next();
}

template<typename T>
list_iterator<T>::operator bool() const
{
    return this->ptr.lock() != nullptr;
}

template<typename T>
list_iterator<T> &list_iterator<T>::operator++()
{
    this->next();
    return this;
}

template<typename T>
list_iterator<T> list_iterator<T>::operator++(int)
{
    list_iterator<T> listIterator(this);
    this->next();
    return listIterator;
}

template<typename T>
list_node<T> &list_iterator<T>::operator*() const
{
    return *this->ptr.lock();
}

template<typename T>
list_iterator<T> &list_iterator<T>::operator=(const list_iterator<T> &listIterator)
{
    this->ptr = listIterator.ptr;
}

template<typename T>
list_iterator<T> &list_iterator<T>::operator=(list_iterator<T> &&listIterator) noexcept
{
    this->ptr = listIterator.ptr;
}

template<typename T>
list_node<T> &list_iterator<T>::operator->() const
{
    return this->ptr.lock()->get();
}

template<typename T>
bool list_iterator<T>::operator==(const list_iterator<T> &iterator)
{
    return this->ptr.lock() == iterator.ptr.lock();
}

template<typename T>
bool list_iterator<T>::operator!=(const list_iterator<T> &iterator)
{
    return this->ptr.lock() != iterator.ptr.lock();
}

template<typename T>
list_iterator<T> list_iterator<T>::operator+(const int size) const
{
    list_iterator<T> tmp(this);

    for (int i = 0; i < size; ++i)
    {
        tmp.next();
    }

    return tmp;
}

template<typename T>
list_iterator<T> &list_iterator<T>::operator+=(const int size)
{
    for (int i = 0; i < size; ++i)
    {
        this->next();
    }
    return *this;
}

#endif //LAB_02_LIST_ITERATOR_HPP
