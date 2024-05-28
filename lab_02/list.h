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

    template<succeed_type U>
        requires(std::convertible_to<U, T>)
    explicit list(const list<U> &list);

    list<T> &operator=(const list<T> &list);

    template<succeed_type U>
        requires(std::convertible_to<U, T>)
    list<T> &operator=(const list<U> &list);

    list(list<T> &&list) noexcept;

    list<T> &operator=(list<T> &&list) noexcept;

    ~list() = default;

    template<succeed_type U>
        requires std::convertible_to<U, T>
    list(const U *arr, int size);

    template<succeed_type U>
        requires std::convertible_to<U, T>
    list(std::initializer_list<U> nodes);

    template<Iterator it>
    list(const it &begin, const it &end);

    template<succeed_type U>
        requires std::convertible_to<U, T>
    list_iterator<T> push_front(const U &data);

    template<succeed_type U>
        requires std::convertible_to<U, T>
    list_iterator<T> push_front(const list<U> &data);

    template<succeed_type U>
        requires std::convertible_to<U, T>
    list_iterator<T> push_back(const U &data);

    template<succeed_type U>
        requires std::convertible_to<U, T>
    list_iterator<T> push_back(const list<U> &list);

    template<succeed_type U>
        requires std::convertible_to<U, T>
    list_iterator<T> insert(const list_iterator<U> &iterator, const U &data);

    template<succeed_type U>
        requires std::convertible_to<U, T>
    list_iterator<T> insert(const list_iterator<U> &iterator, const list<U> &data);

    template<succeed_type U>
        requires std::convertible_to<U, T>
    list<T> &merge(const U &data);

    template<succeed_type U>
        requires std::convertible_to<U, T>
    list<T> &merge(const list<U> &data);

    template<succeed_type U>
        requires std::convertible_to<U, T>
    list<T> &operator+=(const U &data);

    template<succeed_type U>
        requires std::convertible_to<U, T>
    list<T> &operator+=(const list<U> &list);

    template<succeed_type U>
        requires std::convertible_to<U, T>
    list<T> operator+(const U &data);

    template<succeed_type U>
        requires std::convertible_to<U, T>
    list<T> operator+(const list<U> &data);

    T pop_back();

    T pop_front();

    T remove(const list_iterator<T> &iterator);

    bool is_empty() override;

    void clear() override;

    int get_size() override;

    void reverse();

    list_iterator<T> begin() const;

    list_iterator<T> end() const;

    const_list_iterator<T> cbegin() const;

    const_list_iterator<T> cend() const;

    list<T> sublist(const_list_iterator<T>, const_list_iterator<T>) const;

    template<succeed_type U>
        requires std::convertible_to<U, T>
    bool operator==(const list<U> &data) const;

    template<succeed_type U>
        requires std::convertible_to<U, T>
    bool operator!=(const list<U> &data) const;

protected:
    list_iterator<T> push_back(const std::shared_ptr<list_node<T> > &node);

    list_iterator<T> push_front(const std::shared_ptr<list_node<T> > &node);

    std::shared_ptr<list_node<T> > get_head();

    std::shared_ptr<list_node<T> > get_tail();

private:
    std::shared_ptr<list_node<T> > head;
    std::shared_ptr<list_node<T> > tail;
    int size{};
};

#include "list.hpp"

#endif //LAB_02_LIST_H
