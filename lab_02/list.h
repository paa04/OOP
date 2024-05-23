//
// Created by paa04 on 03.05.2024.
//

#ifndef LAB_02_LIST_H
#define LAB_02_LIST_H

#include "base_container.h"
#include "list_iterator.h"
#include "const_list_iterator.h"
#include "list_node.h"
#include "concepts.h"
#include "errors.h"
#include <exception>
#include <chrono>

template<succeed_type T>
class list : public BaseContainer
{
public:
    using iterator = list_iterator<T>;
    using const_iterator = const_list_iterator<T>;

    list();

    explicit list(const list<T> &list);

    list<T> &operator=(const list<T> &list);

    list(list<T> &&list) noexcept;

    list<T> &operator=(list <T> &&list) noexcept;

    ~list() = default;

    list(const T *arr, int size);

    list(std::initializer_list<T> nodes);

    template<Iterator it>
    list(const it &begin, const it &end);

    list(const const_list_iterator<T> &cbegin, const const_list_iterator<T> &cend);

    list_iterator<T> push_front(const T &data);

    list_iterator<T> push_front(const list<T> &data);

    list_iterator<T> push_back(const T &data);

    list_iterator<T> push_back(const list<T> &list);

    list_iterator<T> insert(const list_iterator<T> &iterator, const T &data);

    list_iterator<T> insert(const list_iterator<T> &iterator, const list<T> &data);

    list<T>& merge(const T& data);

    list<T>& merge(const list<T>& data);

    list<T> &operator+=(const T &data);

    list<T> &operator+=(const list <T> &list);

    list<T> operator+(const T &data);

    list<T> operator+(const list <T> &data);

    T pop_back();

    T pop_front();

    T remove(const list_iterator<T> &iterator);

    list<T> &operator-=(const T &data);

    list<T> operator-(const T &data);

    bool is_empty() override;

    void clear() override;

    int get_size() override;

    void reverse();

    list_iterator<T> begin() const;

    list_iterator<T> end() const;

    const_list_iterator<T> cbegin() const;

    const_list_iterator<T> cend() const;

    bool operator==(const list <T> &data) const;

    bool operator!=(const list <T> &data) const;

protected:
    list_iterator<T> push_back(const std::shared_ptr<list_node<T>> &node);

    list_iterator<T> push_front(const std::shared_ptr<list_node<T>> &node);

    std::shared_ptr<list_node<T>> get_head();

    std::shared_ptr<list_node<T>> get_tail();

private:
    std::shared_ptr<list_node<T>> head;
    std::shared_ptr<list_node<T>> tail;
    int size{};
};

#include "list.hpp"

#endif //LAB_02_LIST_H
