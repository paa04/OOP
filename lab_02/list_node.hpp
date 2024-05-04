//
// Created by paa04 on 03.05.2024.
//

#ifndef LAB_02_LIST_NODE_HPP
#define LAB_02_LIST_NODE_HPP

template<typename T>
list_node<T>::list_node()
{
    this->next = nullptr;
}

template<typename T>
list_node<T>::list_node(const T &data)
{
    this->data = data;
    this->next = nullptr;
}

template<typename T>
list_node<T>::list_node(std::shared_ptr<list_node<T>> &node)
{
    this->data = node->data;
    this->next = node->next;
}

template<typename T>
void list_node<T>::set(const T &data)
{
    this->data = data;
}

template<typename T>
void list_node<T>::set_next(const std::shared_ptr<list_node<T>> &node)
{
    this->next = node;
}

template<typename T>
void list_node<T>::set_next(const list_node<T> &node)
{
    this->next = std::make_shared<list_node<T>>(node);
}

template<typename T>
void list_node<T>::set_null()
{
    this->next = nullptr;
}

template<typename T>
const T &list_node<T>::get() const
{
    return this->data;
}

template<typename T>
T& list_node<T>::get_value()
{
    return this->data;
}

template<typename T>
std::shared_ptr<list_node<T>> list_node<T>::get_next()
{
    return this->next;
}

template<typename T>
bool list_node<T>::operator==(const std::shared_ptr<list_node<T>> &node) const
{
    return this == node;
}

template<typename T>
bool list_node<T>::operator!=(const std::shared_ptr<list_node<T>> &node) const
{
    return this != node;
}


#endif //LAB_02_LIST_NODE_HPP
