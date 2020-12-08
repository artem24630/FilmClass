//
// Created by at020 on 01.12.2020.
//

#include "MyString.h"
#include "Exception.h"
#include <iostream>
#include <cstring>

MyString::MyString(char *str2)
{
    int lenStr2 = 1;
    for (int i = 0; str2[i]; ++i) {
        lenStr2++;
    }
    str_ = new char[lenStr2];
    length_ = lenStr2 - 1;
    for (int i = 0; i <= length_; ++i) {
        str_[i] = str2[i];
    }
}
MyString::MyString()
{
    str_ = new char[100];
    length_ = 99;
}
int MyString::getLength() const
{
    return length_;
}
void MyString::setStr(char *str2)
{
    delete[] str_;
    int lenStr2 = 0;
    for (int i = 0; str2[i]; ++i) {
        lenStr2++;
    }
    str_ = new char[lenStr2 + 1];
    length_ = lenStr2 + 1;
    for (int i = 0; i < length_; ++i) {
        str_[i] = str2[i];
    }
}
MyString::~MyString()
{
    delete[] str_;
    length_ = 0;
}
char &MyString::operator[](size_t i) const
{
    if (i <= length_ + 1)
        return str_[i];
    else
        throw Exception("Array index out of bounds");
}
MyString::MyString(int length) : length_(length)
{
    if (length > 0)
        str_ = new char[length + 1];
    for (int i = 0; i < length; i++)
        str_[i] = ' ';
    str_[length] = '\0';
}
MyString::MyString(const MyString &myString)
{
    length_ = myString.length_;
    str_ = new char[length_ + 1];
    for (int i = 0; i < length_ + 1; ++i) {
        str_[i] = myString.str_[i];
    }
}
MyString &MyString::operator=(const MyString &myString)
{
    if (&myString == this) { return *this; }
    delete[] str_;
    if (myString.length_ == 0) {
        length_ = 0;
        str_ = nullptr;
    } else {
        length_ = myString.length_;
        str_ = new char[length_ + 1];
        for (int i = 0; i < length_ + 1; ++i) {
            str_[i] = myString.str_[i];
        }
    }
    return *this;
}
char *MyString::getCharArray()
{
    return str_;
}
char MyString::getCharAt(int index) const
{
    if (index >= 0 && index <= length_)
        return str_[index];
    else
        throw Exception("Array index out of bounds");
}
MyString::MyString(MyString &&myString) noexcept
{
    if (myString.length_ == 0) {
        length_ = 0;
        str_ = new char[1];
        str_[0] = '\0';
    } else {
        length_ = myString.length_;
        str_ = new char[length_ + 1];
        for (int i = 0; i < length_ + 1; ++i) {
            str_[i] = myString.str_[i];
        }
    }
}
MyString &MyString::operator=(MyString &&myString) noexcept
{
    if (&myString == this) return *this;
    delete[] str_;
    if (myString.length_ == 0) {
        length_ = 0;
        str_ = new char[1];
        str_[0] = '\0';
    } else {
        length_ = myString.length_;
        str_ = new char[length_ + 1];
        for (int i = 0; i < length_ + 1; ++i) {
            str_[i] = myString.str_[i];
        }
    }
    return *this;
}
MyString::MyString(std::string s)
{
    length_ = s.length();
    if (length_ >= 0) {
        str_ = new char[length_ + 1];
        for (int i = 0; s[i]; ++i) {
            str_[i] = s[i];
        }
        str_[length_] = '\0';
    } else {
        str_ = nullptr;
    }
}
MyString &MyString::operator=(const std::string s)
{
    delete[] str_;
    length_ = s.length();
    if (length_ >= 0) {
        str_ = new char[length_ + 1];
        for (int i = 0; s[i]; ++i) {
            str_[i] = s[i];
        }
        str_[length_] = '\0';
    } else {
        str_ = nullptr;
    }
    return *this;
}
bool MyString::isEqual(MyString &myString)
{
    if (myString.length_ != length_)
        return false;
    for (int i = 0; i < length_; ++i) {
        if (str_[i] != myString.str_[i])
            return false;
    }
    return true;
}
std::istream &operator>>(std::istream &in, MyString &mString)
{
    char input[1024];
    in.getline(input, sizeof input);
    mString = input;
    return in;
}
MyString &MyString::operator=(const char *str2)
{
    delete[] str_;
    int lenStr2 = 0;
    for (int i = 0; str2[i]; ++i) {
        lenStr2++;
    }
    if (lenStr2 != 0) {
        str_ = new char[lenStr2 + 1];
        length_ = lenStr2;
        for (int i = 0; i < length_ + 1; ++i) {
            str_[i] = str2[i];
        }
    } else {
        length_ = 0;
        str_ = nullptr;
    }
    return *this;
}
std::ostream &operator<<(std::ostream &out, const MyString &mString)
{
    out << mString.str_;
    return out;
}
std::string MyString::getString()
{
    if (str_ != nullptr) {
        std::string tmp(str_);
        return tmp;
    }
    return std::string("");
}
MyString MyString::operator+(const char *array)
{
    MyString resultString;
    int lenArray = 1;
    for (int i = 0; array[i]; ++i) {
        lenArray++;
    }
    char *tmp = new char[lenArray + length_];
    for (int i = 0; i < length_; ++i) {
        tmp[i] = str_[i];
    }
    for (int i = 0; i < lenArray; ++i) {
        tmp[i + length_] = array[i];
    }
    resultString.setStr(tmp);
    return resultString;
}
MyString MyString::operator+(const MyString &array)
{
    MyString resultString;
    int lenArray = 1;
    for (int i = 0; array[i]; ++i) {
        lenArray++;
    }
    char *tmp = new char[lenArray + length_];
    for (int i = 0; i < length_; ++i) {
        tmp[i] = str_[i];
    }
    for (int i = 0; i < lenArray; ++i) {
        tmp[i + length_] = array[i];
    }
    resultString.setStr(tmp);
    return resultString;
}
bool MyString::operator<(const MyString &myString)
{
    return strcmp(str_, myString.str_) < 0;
}
bool MyString::operator>(const MyString &myString)
{
    return strcmp(str_, myString.str_) > 0;;
}
bool MyString::operator==(const MyString &myString)
{
    return strcmp(str_, myString.str_) == 0;
}
