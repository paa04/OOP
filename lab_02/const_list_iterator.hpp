//
// Created by paa04 on 04.05.2024.
//

#ifndef LAB_02_CONST_LIST_ITERATOR_HPP
#define LAB_02_CONST_LIST_ITERATOR_HPP

template<typename T>
const_list_iterator<T>::const_list_iterator()
{
    this->ptr.lock() = nullptr;
}

template<typename T>
const_list_iterator<T>::const_list_iterator(const const_list_iterator<T> &iterator)
{
    this->ptr = iterator.ptr;
}

template<typename T>
const_list_iterator<T>::const_list_iterator(const std::shared_ptr<list_node<T>> &ptr)
{
    this->ptr = ptr;
}

template<typename T>
void const_list_iterator<T>::next()
{
    if (!this->ptr.expired())
        this->ptr = this->ptr.lock()->get_next();
}

template<typename T>
const_list_iterator<T>::operator bool() const
{
    return this->ptr.lock() != nullptr;
}

template<typename T>
bool const_list_iterator<T>::is_valid() const
{
    return !this->ptr.expired();
}

template<typename T>
const_list_iterator<T> &const_list_iterator<T>::operator=(const const_list_iterator<T> &listIterator)
{
    this->ptr = listIterator.ptr;
    return *this;
}

template<typename T>
const_list_iterator<T> &const_list_iterator<T>::operator=(const_list_iterator<T> &&listIterator) noexcept
{
    this->ptr - listIterator.ptr;
    *this;
}

template<typename T>
const list_node<T> &const_list_iterator<T>::operator*() const
{
    return *this->ptr.lock();
}

template<typename T>
const list_node<T> *const_list_iterator<T>::operator->() const
{
    return this->ptr.lock().get();
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
    const_list_iterator<T> tmp(*this);
    ++(*this);
    return tmp;
}

template<typename T>
const_list_iterator<T> &const_list_iterator<T>::operator+=(const int size)
{
    for (int i = 0; i < size; ++i)
        this->next();

    return *this;
}

template<typename T>
const_list_iterator<T> const_list_iterator<T>::operator+(int size) const
{
    const_list_iterator<T> tmp(*this);

    tmp += size;

    return tmp;
}

template<typename T>
bool const_list_iterator<T>::operator==(const const_list_iterator<T> &iterator) const
{
    return this->ptr.lock() == iterator.ptr.lock();
}

template<typename T>
bool const_list_iterator<T>::operator!=(const const_list_iterator<T> &iterator) const
{
    return this->ptr.lock() != iterator.ptr.lock();
}

#endif //LAB_02_CONST_LIST_ITERATOR_HPP
