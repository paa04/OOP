//
// Created by paa04 on 03.05.2024.
//

#ifndef LAB_02_LIST_NODE_H
#define LAB_02_LIST_NODE_H

#include <memory>

template<typename T>
class list_node
{
public:
    list_node();

    explicit list_node(const T &data);

    explicit list_node(std::shared_ptr<list_node<T>> &node);

    ~list_node() = default;

    void set(const T &data);

    void set_next(const std::shared_ptr<list_node<T>> &node);

    void set_next(const list_node<T> &node);

    void set_null();

    T& get_value();

    const T& get() const;

    std::shared_ptr<list_node<T>> get_next();

    bool operator==(const std::shared_ptr<list_node<T>> &node) const;
    bool operator!=(const std::shared_ptr<list_node<T>> &node) const;

private:
    std::shared_ptr<T> next;
    T data;
};

#include "list_item.hpp"

#endif //LAB_02_LIST_NODE_H
