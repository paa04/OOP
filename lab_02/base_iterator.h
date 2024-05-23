//
// Created by paa04 on 17.05.24.
//

#ifndef LAB_02_BASE_ITERATOR_H
#define LAB_02_BASE_ITERATOR_H

#include <iterator>
#include <memory>

template<typename T>
class base_iterator
{
public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = T;

protected:
    base_iterator() = default;



    std::weak_ptr<T> ptr;
};

#endif //LAB_02_BASE_ITERATOR_H
