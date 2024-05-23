//
// Created by paa04 on 07.05.2024.
//

#ifndef LAB_02_CONCEPTS_H
#define LAB_02_CONCEPTS_H

#include <concepts>

template<typename T>
concept succeed_type = std::destructible<T> && std::copyable<T> && std::movable<T>
                       && std::default_initializable<T>;

template<typename Container>
concept succeed_container =
requires(Container c)
{
    { c.cbegin() } -> std::same_as<typename Container::const_iterator>;
    { c.cend() } -> std::same_as<typename Container::const_iterator>;
};

template<typename T>
concept Iterator = requires(T iter) {
    {*iter};
    {++iter} -> std::same_as<T&>;
    {iter++} -> std::same_as<T>;
    {iter == iter} -> std::convertible_to<bool>;
    {iter != iter} -> std::convertible_to<bool>;
};


#endif //LAB_02_CONCEPTS_H
