//
// Created by paa04 on 03.05.2024.
//

#ifndef LAB_02_LIST_HPP
#define LAB_02_LIST_HPP

template<typename T>
list<T>::list()
{
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

template<typename T>
list<T>::list(list<T> &&list) noexcept
{
    this->size = list.size;
    this->head = list.head;
    this->tail = list.tail;
}

template<typename T>
list<T> &list<T>::operator=(list<T> &&list) noexcept
{
    this->head = list.head;
    this->tail = list.tail;
    this->size = list.size;
}

template<typename T>
list_iterator<T> list<T>::begin()
{
    return list_iterator<T>(this->head);
}

template<typename T>
list_iterator<T> list<T>::end()
{
    return list_iterator<T>(this->tail);
}

#endif //LAB_02_LIST_HPP
