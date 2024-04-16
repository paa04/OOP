//
// Created by paa04 on 15.04.24.
//

#ifndef LIST_HPP
#define LIST_HPP
#include <list_item.hpp>
#include <memory>

template<typename Type>
class List
{
public:
    List();
    explicit List(int n);


private:
    std::shared_ptr<List> head;
    std::shared_ptr<List> tail;
};

template<typename Type>
List<Type>::List() = default;

template<typename Type>
List<Type>::List(int n)
{
    for (int i = 0; i < n; ++i)
    {

    }
}


#endif //LIST_HPP
