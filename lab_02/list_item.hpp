//
// Created by paa04 on 15.04.24.
//

#ifndef LIST_ITEM_HPP
#define LIST_ITEM_HPP
#include <memory>


template<typename Type>
class ListItem
{
public:
    ListItem();
    explicit ListItem(Type data); // Правая ссылка
    // explicit ListItem(Type &&data);

    ListItem get_next_pointer();
    Type get_value();


private:
    std::shared_ptr<ListItem> next;
    std::shared_ptr<Type> data;
};

template<typename Type>
ListItem<Type>::ListItem() = default;

template<typename Type>
ListItem<Type>::ListItem(Type data)
{
    this->data = std::make_shared<Type>(data);
    this->next = nullptr;
}

template<typename Type>
Type ListItem<Type>::get_value()
{
    return *this->data.get();
}

template<typename Type>
ListItem<Type> ListItem<Type>::get_next_pointer()
{
    return this->next;
}




#endif //LIST_ITEM_HPP
