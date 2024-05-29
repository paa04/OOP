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
protected:
    base_error(std::string time,
               std::string filename, std::string classname, std::string methodname, std::string info)
    {
        snprintf(error_info, 256, "\nTime: %sFile: %s\nClass: %s\nMethod: %s\nInfo: %s\n", time.c_str(),
                 filename.c_str(),
                 classname.c_str(), methodname.c_str(), info.c_str());
    }

    const char *what() const noexcept override
    {
        return error_info;
    }

    char error_info[256];
};

class ListError : public base_error
{
protected:
    ListError(std::string time,
              std::string filename, std::string classname, std::string methodname, std::string info): base_error(time,
        filename, classname, methodname, info)
    {
    }
};

class IterError : public base_error
{
protected:
    IterError(std::string time,
              std::string filename, std::string classname, std::string methodname, std::string info): base_error(time,
        filename, classname, methodname, info)
    {
    }
};

class AllocError : public base_error
{
protected:
    AllocError(std::string time,
               std::string filename, std::string classname, std::string methodname, std::string info): base_error(time,
        filename, classname, methodname, info)
    {
    }
};

class mem_error : public AllocError
{
public:
    mem_error(std::string time, std::string filename,
              std::string classname, std::string methodname)
        : AllocError(time, filename, classname, methodname, "error: Unable to allocate memory.")
    {
    };
};

class empty_list : public ListError
{
public:
    empty_list(std::string time, std::string filename,
               std::string classname, std::string methodname) : ListError(
        time, filename, classname, methodname, "error: Empty list")
    {
    };
};

class iterator_error : public IterError
{
public:
    iterator_error(std::string time, std::string filename,
                   std::string classname, std::string methodname) : IterError(
        time, filename, classname, methodname, "error: Bad iterator")
    {
    };
};

class pointer_error : public IterError
{
public:
    pointer_error(std::string time, std::string filename, std::string classname, std::string methodname): IterError(
        time, filename, classname, methodname, "error: Bad pointer")
    {
    };
};

class size_error : public ListError
{
public:
    size_error(std::string time, std::string filename, std::string classname, std::string methodname) : ListError(
        time, filename, classname, methodname, "error: The size passed to the method is invalid.")
    {
    };
};

#endif //LAB_02_ERRORS_H
