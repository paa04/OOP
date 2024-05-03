//
// Created by paa04 on 03.05.2024.
//

#ifndef LAB_02_LIST_H
#define LAB_02_LIST_H

#include "base_container.h"
#include "list_iterator.h"

template<typename T>
class list : public BaseContainer
{
public:
    list();

    explicit list(const list<T> &data);

    list<T> &operator=(const list<T> &list);

    list(list<T> &&list) noexcept;

    list<T> &operator=(list <T> &&list) noexcept;

    list_iterator<T> begin();
    list_iterator<T> end();

private:
    std::shared_ptr<list<T>> head;
    std::shared_ptr<list<T>> tail;
    int size{};
};

#include "list.hpp"

#endif //LAB_02_LIST_H
