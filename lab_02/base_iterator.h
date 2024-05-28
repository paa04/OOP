//
// Created by paa04 on 17.05.24.
//

#ifndef LAB_02_BASE_ITERATOR_H
#define LAB_02_BASE_ITERATOR_H

#include <iterator>
#include <memory>
#include "concepts.h"

template<succeed_type T>
class BaseIterator
{
public:
    using iterator_category = std::input_iterator_tag;
    using value_type = T;
protected:
    BaseIterator() = default;
    std::weak_ptr<list_node<T>> ptr;
};

#endif //LAB_02_BASE_ITERATOR_H
