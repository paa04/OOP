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
concept good_container =
requires(Container c)
{
    { c.cbegin() } -> std::same_as<typename Container::const_iterator>;
    { c.cend() } -> std::same_as<typename Container::const_iterator>;
};

#endif //LAB_02_CONCEPTS_H
