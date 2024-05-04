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
list<T>::list(const list<T> &list)
{
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;

    for (auto node = list.cbegin(); node != list.cend(); ++node)
    {
        std::shared_ptr<list_node<T>> temp_node(new list_node<T>);

        //todo check alloc

        temp_node->set((*node).get());
        this->push_back(temp_node);
    }
}

template<typename T>
list<T>::list(list<T> &&list) noexcept
{
    this->size = list.size;
    this->head = list.head;
    this->tail = list.tail;
}

template<typename T>
list<T> &list<T>::operator=(const list<T> &list)
{
    this->clear();

    for (auto node = list.cbegin(); node != list.cend(); ++node)
    {
        std::shared_ptr<list_node<T>> temp_node(new list_node<T>);

        //todo check alloc

        temp_node->set((*node).get());
        this->push_back(temp_node);
    }
}

template<typename T>
list<T> &list<T>::operator=(list<T> &&list) noexcept
{
    this->head = list.head;
    this->tail = list.tail;
    this->size = list.size;
}

template<typename T>
list_iterator<T> list<T>::push_back(const std::shared_ptr<list_node<T>> &node)
{
    if (!node)
    {
        throw std::exception();
    }

    std::shared_ptr<list_node<T>> tmp_node(new list_node<T>);

    //TODO mem alloc check

    tmp_node->set(node->get());

    if (!this->size)
    {
        this->head = tmp_node;
        this->tail = tmp_node;
    }
    else
    {
        this->tail->set_next(tmp_node);
        this->tail = tmp_node;
    }

    ++this->size;

    return list_iterator<T>(this->tail);
}

template<typename T>
list_iterator<T> list<T>::push_back(const T &data)
{
    std::shared_ptr<list_node<T>> tmp{std::make_shared<list_node<T>>()};

    tmp->set(data);

    return this->push_back(tmp);
}

template<typename T>
list_iterator<T> list<T>::push_back(const list_node<T> &node)
{
    std::shared_ptr<list_node<T>> tmp{std::make_shared<list_node<T>>()};
    //TODO check alloc
    *tmp = node;

    this->push_back(tmp);
}

template<typename T>
list_iterator<T> list<T>::begin() const
{
    return list_iterator<T>(this->head);
}

template<typename T>
list_iterator<T> list<T>::end() const
{
    return ++list_iterator<T>(this->tail);
}

template<typename T>
const_list_iterator<T> list<T>::cbegin() const
{
    return const_list_iterator<T>(this->head);
}

template<typename T>
const_list_iterator<T> list<T>::cend() const
{
    return ++const_list_iterator<T>(this->tail);
}

template<typename T>
std::shared_ptr<list_node<T>> list<T>::get_head()
{
    return head;
}

template<typename T>
std::shared_ptr<list_node<T>> list<T>::get_tail()
{
    return tail;
}

template<typename T>
T list<T>::pop_front()
{
    if (!this->size)
    {
        throw std::exception();
    }

    T data = this->head->get();

    if(this->size == 1)
    {
        this->tail = nullptr;
    }

    this->head = this->head->get_next();

    --this->size;

    return data;
}

template<typename T>
bool list<T>::is_empty()
{
    return begin() == end();
}

template<typename T>
void list<T>::clear()
{
    while (this->size)
        this->pop_front();
}

#endif //LAB_02_LIST_HPP
