//
// Created by paa04 on 03.05.2024.
//

#ifndef LAB_02_LIST_H
#define LAB_02_LIST_H

#include "base_container.h"
#include "list_iterator.h"
#include "const_list_iterator.h"
#include "list_node.h"
#include <exception>

template<typename T>
class list : public BaseContainer
{
public:
    list();

    explicit list(const list<T> &list);

    list<T> &operator=(const list<T> &list);

    list(list<T> &&list) noexcept;

    ~list() = default;

    list<T> &operator=(list <T> &&list) noexcept;

    list_iterator<T> push_back(const T &data);
    list_iterator<T> push_back(const list_node<T> &node);

    T pop_front();

    bool is_empty() override;
    void clear() override;

    list_iterator<T> begin() const;
    list_iterator<T> end() const;

    const_list_iterator<T> cbegin() const;
    const_list_iterator<T> cend() const;

protected:
    list_iterator<T> push_back(const std::shared_ptr<list_node<T>> &node);
    std::shared_ptr<list_node<T>> get_head();
    std::shared_ptr<list_node<T>> get_tail();

private:
    std::shared_ptr<list_node<T>> head;
    std::shared_ptr<list_node<T>> tail;
    int size{};
};

#include "list.hpp"

#endif //LAB_02_LIST_H
