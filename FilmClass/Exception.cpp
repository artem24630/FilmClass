//
// Created by at020 on 06.12.2020.
//

#include "Exception.h"

Exception::Exception(const char *msg_) {
    msg = msg_;
}

Exception::Exception(MyString msg_) {
    msg = msg_;
}

const MyString &Exception::get_msg() const {
    return msg;
}
