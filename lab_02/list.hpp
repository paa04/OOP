//
// Created by paa04 on 03.05.2024.
//

#ifndef LAB_02_LIST_HPP
#define LAB_02_LIST_HPP

template<succeed_type T>
list<T>::list()
{
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

template<succeed_type T>
list<T>::list(const list<T> &list)
{
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;

    for (auto node = list.cbegin(); node != list.cend(); ++node)
    {
        std::shared_ptr<list_node<T>> temp_node = nullptr;

        try
        {
            temp_node = std::make_shared<list_node<T>>();
        }
        catch (std::bad_alloc &)
        {
            auto time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            throw mem_error(ctime(&time), __FILE__, typeid(list).name(), __FUNCTION__);
        }

        temp_node->set((*node).get());
        this->push_back(temp_node);
    }
}

template<succeed_type T>
list<T>::list(list<T> &&list) noexcept
{
    this->size = list.size;
    this->head = list.head;
    this->tail = list.tail;
}

template<succeed_type T>
list<T>::list(const T *arr, int size)
{
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;

    if (!arr)
    {
        auto time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw pointer_error(ctime(&time), __FILE__, typeid(list).name(), __FUNCTION__);
    }

    if (size <= 0)
    {
        auto time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw size_error(ctime(&time), __FILE__, typeid(list).name(), __FUNCTION__);
    }

    for (int i = 0; i < size; ++i)
    {
        this->push_back(arr[i]);
    }
}

template<succeed_type T>
list<T>::list(std::initializer_list<T> nodes)
{
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;

    for (auto node: nodes)
    {
        this->push_back(node);
    }
}

template<succeed_type T>
template<Iterator it>
list<T>::list(const it &begin, const it &end)
{
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;

    for (auto i = begin; i != end; ++i)
    {
        this->push_back(*i);
    }
}

template<succeed_type T>
list<T>::list(const const_list_iterator<T> &cbegin,
              const const_list_iterator<T> &cend)
{
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;

    for (auto it = cbegin; it != cend; ++it)
    {
        this->push_back(it->get());
    }
}

template<succeed_type T>
list<T> &list<T>::operator=(const list<T> &list)
{
    this->clear();

    for (auto node = list.cbegin(); node != list.cend(); ++node)
    {
        std::shared_ptr<list_node<T>> temp_node = nullptr;

        try
        {
            temp_node = std::make_shared<list_node<T>>();
        } catch (std::bad_alloc &error)
        {
            auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            throw mem_error(ctime(&timenow), __FILE__, typeid(list).name(), __FUNCTION__);
        }

        temp_node->set((*node).get());
        this->push_back(temp_node);
    }

    return *this;
}

template<succeed_type T>
list<T> &list<T>::operator=(list<T> &&list) noexcept
{
    this->head = list.head;
    this->tail = list.tail;
    this->size = list.size;

    return *this;
}

template<succeed_type T>
list_iterator<T> list<T>::push_back(const std::shared_ptr<list_node<T>> &node)
{
    if (!node)
    {
        auto time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw pointer_error(ctime(&time), __FILE__, typeid(list).name(), __FUNCTION__);
    }

    std::shared_ptr<list_node<T>> tmp_node = nullptr;

    try
    {
        tmp_node = std::make_shared<list_node<T>>();
    } catch (std::bad_alloc &exec)
    {
        auto time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw mem_error(ctime(&time), __FILE__, typeid(list).name(), __FUNCTION__);
    }

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

template<succeed_type T>
list_iterator<T> list<T>::push_front(const std::shared_ptr<list_node<T>> &node)
{
    if (!node)
    {
        auto time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw pointer_error(ctime(&time), __FILE__, typeid(list).name(), __FUNCTION__);
    }

    node->set_next(this->head);
    this->head = node;

    if (!this->size)
    {
        this->tail = this->head;
    }

    ++this->size;

    list_iterator<T> iterator(node);
    return iterator;
}

template<succeed_type T>
list_iterator<T> list<T>::push_back(const T &data)
{
    std::shared_ptr<list_node<T>> tmp{std::make_shared<list_node<T>>()};

    tmp->set(data);

    return this->push_back(tmp);
}

template<succeed_type T>
list_iterator<T> list<T>::push_back(const list<T> &list)
{
    for (auto node = list.cbegin(); node != list.cend(); ++node)
    {
        std::shared_ptr<list_node<T>> temp_node = nullptr;

        try
        {
            temp_node = std::make_shared<list_node<T>>();
        } catch (std::bad_alloc &exec)
        {
            auto time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            throw mem_error(ctime(&time), __FILE__, typeid(list).name(), __FUNCTION__);
        }

        temp_node->set((*node).get());
        this->push_back(temp_node);
    }

    return list_iterator<T>(this->tail);
}

template<succeed_type T>
list<T> &list<T>::merge(const T &data)
{
    this->push_back(data);
    return *this;
}

template<succeed_type T>
list<T> &list<T>::merge(const list<T> &data)
{
    this->push_back(data);
    return *this;
}

template<succeed_type T>
void list<T>::reverse()
{
    std::shared_ptr<list_node<T>> prev(nullptr);
    std::shared_ptr<list_node<T>> cur(this->head);
    std::shared_ptr<list_node<T>> next(nullptr);

    while (cur)
    {
        next = cur->get_next();
        cur->set_next(prev);
        prev = cur;
        cur = next;
    }

    cur = this->head;
    this->head = this->tail;
    this->tail = cur;
}

template<succeed_type T>
list_iterator<T> list<T>::begin() const
{
    return list_iterator<T>(this->head);
}

template<succeed_type T>
list_iterator<T> list<T>::end() const
{
    return ++list_iterator<T>(this->tail);
}

template<succeed_type T>
const_list_iterator<T> list<T>::cbegin() const
{
    return const_list_iterator<T>(this->head);
}

template<succeed_type T>
const_list_iterator<T> list<T>::cend() const
{
    return ++const_list_iterator<T>(this->tail);
}

template<succeed_type T>
std::shared_ptr<list_node<T>> list<T>::get_head()
{
    return head;
}

template<succeed_type T>
std::shared_ptr<list_node<T>> list<T>::get_tail()
{
    return tail;
}

template<succeed_type T>
T list<T>::pop_front()
{
    if (!this->size)
    {
        auto time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw size_error(ctime(&time), __FILE__, typeid(list).name(), __FUNCTION__);
    }

    T data = this->head->get();

    if (this->size == 1)
    {
        this->tail = nullptr;
    }

    this->head = this->head->get_next();

    --this->size;

    return data;
}

template<succeed_type T>
T list<T>::remove(const list_iterator<T> &iterator)
{
    if (iterator.is_invalid())
    {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw iterator_error(ctime(&timenow), __FILE__, typeid(list).name(), __FUNCTION__);
    }

    if (!this->size)
    {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw empty_list(ctime(&timenow), __FILE__, typeid(list).name(), __FUNCTION__);
    }

    if (iterator == this->begin())
    {
        return pop_front();
    }

    list_iterator<T> temp_iterator = this->begin();
    for (; temp_iterator + 1 != iterator; temp_iterator++);

    T data = temp_iterator->get();
    temp_iterator->set_next(temp_iterator->get_next()->get_next());
    this->size--;

    return data;
}

template<succeed_type T>
T list<T>::pop_back()
{
    if (!this->size)
    {
        auto time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw size_error(ctime(&time), __FILE__, typeid(list).name(), __FUNCTION__);
    }
    T data;

    if (this->size == 1)
    {
        data = this->head->get();
        this->head = nullptr;
        this->tail = nullptr;
    }
    else
    {
        std::shared_ptr<list_node<T>> ptr = this->head;

        while (ptr->get_next() != this->tail)
        {
            ptr = ptr->get_next();
        }

        data = this->tail->get();

        ptr->set_next(nullptr);
        this->tail = ptr;
    }

    --this->size;

    return data;
}

template<succeed_type T>
bool list<T>::is_empty()
{
    return begin() == end();
}

template<succeed_type T>
void list<T>::clear()
{
    while (this->size)
        this->pop_front();
}

template<succeed_type T>
int list<T>::get_size()
{
    return this->size;
}

template<succeed_type T>
list<T> &list<T>::operator+=(const T &data)
{
    this->push_back(data);
    return *this;
}

template<succeed_type T>
list<T> &list<T>::operator+=(const list <T> &list)
{
    this->push_back(list);
    return *this;
}

template<succeed_type T>
list<T> &list<T>::operator-=(const T &data)
{
    bool find_flag = false;
    for (auto i = this->begin(); !find_flag && i != this->end(); ++i)
    {
        if (i->get() == data)
        {
            list_iterator<T> tmp(i);
            this->remove(tmp);
            find_flag = true;
        }
    }
    return *this;
}

template<succeed_type T>
list<T> list<T>::operator-(const T &data)
{
    list<T> tmp(*this);
    bool find_flag = false;
    for (auto i = tmp->begin(); !find_flag && i != tmp->end(); ++i)
    {
        if (i->get() == data)
        {
            list_iterator<T> temp_it(i);
            tmp.remove(temp_it);
            find_flag = true;
        }
    }
    return tmp;
}

template<succeed_type T>
list<T> list<T>::operator+(const T &data)
{
    list<T> tmp(this);
    tmp.push_back(data);
    return tmp;
}

template<succeed_type T>
list<T> list<T>::operator+(const list <T> &data)
{
    list<T> tmp(*this);
    tmp.push_back(data);
    return tmp;
}

template<succeed_type T>
bool list<T>::operator==(const list <T> &data) const
{
    if (this->size != data.size)
        return false;

    bool ans = true;

    for (auto i = this->cbegin(), j = data.cbegin(); i != this->cend() && ans; ++i, ++j)
    {
        if (*i != *j)
            ans = false;
    }

    return ans;
}

template<succeed_type T>
bool list<T>::operator!=(const list <T> &data) const
{
    return !(*this == data);
}

template<succeed_type T>
list_iterator<T> list<T>::push_front(const T &data)
{
    std::shared_ptr<list_node<T>> ptr = nullptr;

    try
    {
        ptr = std::make_shared<list_node<T>>();
    }
    catch (std::bad_alloc &exception)
    {
        auto time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw mem_error(ctime(&time), __FILE__, typeid(list).name(), __FUNCTION__);
    }

    ptr->set(data);
    ptr->set_next(this->head);
    this->head = ptr;

    ++this->size;

    return list_iterator<T>(this->head);
}

template<succeed_type T>
list_iterator<T> list<T>::push_front(const list<T> &data)
{
    list_iterator<T> iterator;

    for (int i = 0; i < data.size; i++)
    {
        iterator = this->insert(this->begin() + i, (*(data.cbegin() + i)).get());
    }

    return iterator;
}

template<succeed_type T>
list_iterator<T> list<T>::insert(const list_iterator<T> &iterator, const T &data)
{
    if (!iterator.is_valid())
    {
        auto time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw iterator_error(ctime(&time), __FILE__, typeid(list).name(), __FUNCTION__);
    }

    std::shared_ptr<list_node<T>> temp_node = nullptr;

    try
    {
        temp_node = std::make_shared<list_node<T>>();
    } catch (std::bad_alloc &exception)
    {
        auto time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw mem_error(ctime(&time), __FILE__, typeid(list).name(), __FUNCTION__);
    }

    temp_node->set(data);

    if (iterator == this->begin())
    {
        return push_front(temp_node);
    }
    else if (iterator == this->end())
    {
        return this->push_back(temp_node);
    }

    list_iterator<T> temp_iterator = this->begin();
    for (; temp_iterator + 1 != iterator; temp_iterator++);

    temp_node->set_next(temp_iterator->get_next());
    temp_iterator->set_next(temp_node);
    this->size++;

    list_iterator<T> insert_iterator(temp_node);
    return insert_iterator;
}

template<succeed_type T>
list_iterator<T> list<T>::insert(const list_iterator<T> &iterator, const list<T> &list)
{
    if (!iterator.is_valid())
    {
        auto time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw iterator_error(ctime(&time), __FILE__, typeid(list).name(), __FUNCTION__);
    }

    list_iterator<T> insert_iterator;

    for (int i = 0; i < list.size; i++)
    {
        insert_iterator = insert(iterator, (*(list.cbegin() + i)).get());
    }

    return insert_iterator;
}

template<typename T_>
std::ostream &operator<<(std::ostream &os, const list<T_> &list)
{
    for (auto iterator = list.cbegin(); iterator != list.cend(); iterator++)
    {
        os << (*iterator).get() << " ";
    }

    return os;
}

#endif //LAB_02_LIST_HPP
