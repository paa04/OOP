//
// Created by paa04 on 22.04.24.
//

#ifndef BASE_CONTAINER_HPP
#define BASE_CONTAINER_HPP

class base_container
{
public:
    virtual bool is_empty() const = 0;

    virtual void clear() = 0;

    virtual ~base_container() = default;

protected:
    size_t size;
};

#endif //BASE_CONTAINER_HPP
