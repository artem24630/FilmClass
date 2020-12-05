//
// Created by at020 on 01.12.2020.
//

#include "MyString.h"
#include <iostream>
MyString::MyString(char *str2) {
    int lenStr2 = 1;
    for (int i = 0; str2[i]; ++i) {
        lenStr2++;
    }
    str = new char[lenStr2];
    length = lenStr2-1;
    for (int i = 0; i<=length; ++i) {
        str[i] = str2[i];
    }
}

MyString::MyString() {
    str = new char[100];
    length = 99;
}

int MyString::getLength() const {
    return length;
}

void MyString::setStr(char *str2) {
    delete[] str;
    int lenStr2 = 0;
    for (int i = 0; str2[i]; ++i) {
        lenStr2++;
    }
    str = new char[lenStr2+1];
    length = lenStr2+1;
    for (int i = 0; i<lenStr2+1; ++i) {
        str[i] = str2[i];
    }
}

void MyString::set_length() {
    length = 0;
    for (int i = 0; str[i]; ++i) { //определяем длину строки
        length++;
    }
}

MyString::~MyString() {
    delete[] str;
    length = 0;
}

char &MyString::operator[](int i) {
    if (i >= 0 && i <= length + 1)
        return str[i];
    else
        throw "error out of index array";//TODO создать переменные ошибок
}

MyString::MyString(int length) : length(length) { str = new char[length]; }

MyString::MyString(const MyString &myString) {
    length = myString.length;
    str = new char[length + 1];
    for (int i = 0; i < length + 1; ++i) {
        str[i] = myString.str[i];
    }
}

MyString &MyString::operator=(const MyString &myString) {
    if (&myString == this){ return *this; }
    delete[] str;
    if (myString.length == 0) {
        length = 0;
        str = nullptr;
    } else {
        length = myString.length;
        str = new char[length + 1];
        for (int i = 0; i < length + 1; ++i) {
            str[i] = myString.str[i];
        }
    }
    return *this;
}

char* MyString::getCharArray() {
    return str;
}

char MyString::getCharAt(int index) const {
    if (index >= 0 && index <= length)
        return str[index];
    else
        throw "error out of index array";
}

MyString::MyString(MyString &&myString) noexcept {
    if (myString.length == 0) {
        length = 0;
        str = nullptr;
    } else {
        length = myString.length;
        str = new char[length + 1];
        for (int i = 0; i < length + 1; ++i) {
            str[i] = myString.str[i];
        }
    }
}

MyString &MyString::operator=(MyString &&myString) noexcept {
    if (&myString == this) return *this;
    delete[] str;
    if (myString.length == 0) {
        length = 0;
        str = nullptr;
    } else {
        length = myString.length;
        str = new char[length + 1];
        for (int i = 0; i < length + 1; ++i) {
            str[i] = myString.str[i];
        }
    }
    return *this;
}

MyString::MyString(std::string s) {
    length = s.length();
    if (length != 0) {
        str = new char[length];
        for (int i = 0; s[i]; ++i) {
            str[i] = s[i];
        }
    } else {
        str = nullptr;
    }
}

MyString &MyString::operator=(const std::string s) {
    delete[] str;
    length = s.length();
    if (length != 0) {
        str = new char[length];
        for (int i = 0; s[i]; ++i) {
            str[i] = s[i];
        }
    } else {
        str = nullptr;
    }
    return *this;
}

bool MyString::isEqual(MyString &myString) {
    if(myString.length != length)
        return false;
    for (int i = 0; i < length; ++i) {
        if(str[i]!=myString.str[i])
            return false;
    }
    return true;
}

std::istream &operator>>(std::istream &in, MyString &mString) {
    char input[1024];
    in.getline(input, sizeof input);
    mString = input;
    return in;
}

MyString &MyString::operator= (char *str2) {
    delete[] str;
    int lenStr2 = 0;
    for (int i = 0; str2[i]; ++i) {
        lenStr2++;
    }
    if(lenStr2 != 0) {
        str = new char[lenStr2+1];
        length = lenStr2;
        for (int i = 0; i < length + 1; ++i) {
            str[i] = str2[i];
        }
    }else{
        length = 0;
        str = nullptr;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out, MyString &mString) {
    out << mString.str;
    return out;
}

std::string MyString::getString() {
    std::string tmp(str);
    return tmp;
}
