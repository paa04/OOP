//
// Created by paa04 on 03.05.2024.
//

#ifndef LAB_02_LIST_ITERATOR_HPP
#define LAB_02_LIST_ITERATOR_HPP

template<succeed_type T>
list_iterator<T>::list_iterator()
{
    this->ptr.lock() = nullptr;
}

template<succeed_type T>
list_iterator<T>::list_iterator(const std::shared_ptr<list_node<T>> &ptr)
{
    this->ptr = ptr;
}

template<succeed_type T>
list_iterator<T>::list_iterator(const list_iterator<T> &iterator)
{
    this->ptr = iterator.ptr;
}

template<succeed_type T>
std::shared_ptr<list_node<T>> list_iterator<T>::get_node()
{
    return this->ptr.lock();
}

template<succeed_type T>
void list_iterator<T>::next()
{
    if (!this->ptr.expired())
        this->ptr = this->ptr.lock()->get_next();
}

template<succeed_type T>
list_iterator<T>::operator bool() const
{
    return this->ptr.lock() != nullptr;
}

template<succeed_type T>
bool list_iterator<T>::is_valid() const
{
    return !this->ptr.expired();
}

template<succeed_type T>
list_iterator<T> &list_iterator<T>::operator++()
{
    this->next();
    return *this;
}

template<succeed_type T>
list_iterator<T> list_iterator<T>::operator++(int)
{
    list_iterator<T> listIterator(*this);
    this->next();
    return listIterator;
}

template<succeed_type T>
T &list_iterator<T>::operator*() const
{
    return (*this->ptr.lock()).get_value();
}

template<succeed_type T>
T *list_iterator<T>::operator->() const
{
    return &this->ptr.lock()->get();
}

template<succeed_type T>
list_iterator<T> &list_iterator<T>::operator=(const list_iterator<T> &listIterator)
{
    this->ptr = listIterator.ptr;
}

template<succeed_type T>
list_iterator<T> &list_iterator<T>::operator=(list_iterator<T> &&listIterator) noexcept
{
    this->ptr = listIterator.ptr;
    return *this;
}

template<succeed_type T>
bool list_iterator<T>::operator==(const list_iterator<T> &it) const
{
    return this->ptr.lock() == it.ptr.lock();
}


template<succeed_type T>
bool list_iterator<T>::operator!=(const list_iterator<T> &it) const
{
    return this->ptr.lock() != it.ptr.lock();
}


template<succeed_type T>
list_iterator<T> list_iterator<T>::operator+(const int size) const
{
    list_iterator<T> tmp(*this);

    for (int i = 0; i < size; ++i)
    {
        tmp.next();
    }

    return tmp;
}

template<succeed_type T>
list_iterator<T> &list_iterator<T>::operator+=(const int size)
{
    for (int i = 0; i < size; ++i)
    {
        this->next();
    }
    return *this;
}

#endif //LAB_02_LIST_ITERATOR_HPP
