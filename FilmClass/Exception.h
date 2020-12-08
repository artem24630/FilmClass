//
// Created by at020 on 06.12.2020.
//

#ifndef FILMCLASS_EXCEPTION_H
#define FILMCLASS_EXCEPTION_H

#include <MyString.h>

class Exception
{
public:
    Exception() = delete;
    Exception(const char *msg_);
    Exception(MyString msg_);
    ~Exception() = default;
    const MyString &get_msg() const;
private:
    MyString msg;
};

#endif //FILMCLASS_EXCEPTION_H
