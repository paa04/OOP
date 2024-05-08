//
// Created by paa04 on 03.05.2024.
//

#ifndef LAB_02_BASE_CONTAINER_H
#define LAB_02_BASE_CONTAINER_H

class BaseContainer
{
public:
    virtual bool is_empty() = 0;

    virtual void clear() = 0;

    virtual int get_size() = 0;

    virtual ~BaseContainer() = default;

protected:
    int size;
};

#endif //LAB_02_BASE_CONTAINER_H
