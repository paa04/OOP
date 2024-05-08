//
// Created by paa04 on 08.05.2024.
//

#ifndef LAB_02_ERRORS_H
#define LAB_02_ERRORS_H

#include <exception>
#include <string>
#include <cstring>

class base_error : public std::exception
{
public:
    base_error(std::string time,
               std::string filename, std::string classname, std::string methodname)
    {
        error_info = "\nTime: " + time + \
                     "File: " + filename + \
                     "\nClass: " + classname + \
                     "\nMethod: " + methodname;
    }

    virtual const char *what() const noexcept override
    {
        std::string message = "\nERROR: Something is wrong with your list." + error_info;
        char *cmessage = new char[1 + message.size()];
        strcpy(cmessage, message.c_str());
        return cmessage;
    }

protected:
    std::string error_info;
};

class mem_error : public base_error
{
public:
    mem_error(std::string time, std::string filename,
              std::string classname, std::string methodname)
            : base_error(time, filename, classname, methodname)
    {};

    virtual const char *what() const noexcept override
    {
        std::string message = "\nERROR: Unable to allocate memory. " + error_info;
        char *cmessage = new char[1 + message.size()];
        std::strcpy(cmessage, message.c_str());
        return cmessage;
    }
};

class empty_list : public base_error
{
public:
    empty_list(std::string time, std::string filename,
               std::string classname, std::string methodname) :
            base_error(time, filename, classname, methodname)
    {};

    const char *what() const noexcept override
    {
        std::string message = "\nERROR: Empty list. " + error_info;
        char *cmessage = new char[1 + message.size()];
        std::strcpy(cmessage, message.c_str());
        return cmessage;
    }
};

class iterator_error: public base_error
{
public:
    iterator_error(std::string time, std::string filename,
            std::string classname, std::string methodname) :
    base_error(time, filename, classname, methodname)
    {};

    const char * what() const noexcept override
    {
        std::string message = "\nERROR: Bad iterator. " + error_info;
        char *cmessage = new char[1 + message.size()];
        std::strcpy(cmessage, message.c_str());
        return cmessage;
    }
};

class pointer_error : public base_error
{
public:
    pointer_error(std::string time, std::string filename, std::string classname, std::string methodname) :
            base_error(time, filename, classname, methodname) {};

    virtual const char* what() const noexcept override
    {
        std::string message = "\nERROR: Bad pointer. " + error_info;
        char *cmessage = new char[1 + message.size()];
        std::strcpy(cmessage, message.c_str());
        return cmessage;
    }
};

class size_error: public base_error
{
public:
    size_error(std::string time, std::string filename, std::string classname, std::string methodname) :
            base_error(time, filename, classname, methodname) {};

    virtual const char* what() const noexcept override
    {
        std::string message = "\nERROR: The size passed to the method is invalid." + error_info;
        char *cmessage = new char[1 + message.size()];
        std::strcpy(cmessage, message.c_str());
        return cmessage;
    }
};

#endif //LAB_02_ERRORS_H
