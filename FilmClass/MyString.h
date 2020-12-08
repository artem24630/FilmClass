//
// Created by at020 on 01.12.2020.
//

#ifndef FILMCLASS_MYSTRING_H
#define FILMCLASS_MYSTRING_H

#include <string>

class MyString
{
public:
    MyString(char *str2);//конструктор с параметром строки
    explicit MyString(std::string s);//конструктор с параметром string
    explicit MyString(int length);//конструктор с параметром длины
    MyString();//конструктор пустой
    MyString(const MyString &myString);//конструктор копирования
    MyString(MyString &&myString) noexcept;//конструктор переноса
    ~MyString(); //деструктор

    MyString &operator=(const MyString &myString); // оператор копирующего присваивания MyString
    MyString &operator=(std::string s);//оператор присваивания string
    MyString &operator=(const char *str2);//оператор присваивания char*
    MyString &operator=(MyString &&myString) noexcept; //оператор присваивания с переносом

    char &operator[](size_t i) const;//оператор []

    MyString operator+(const char *array);
    MyString operator+(const MyString &array);

    bool operator<(const MyString &myString);
    bool operator>(const MyString &myString);
    bool operator==(const MyString &myString);

    char *getCharArray();//возвращаем символьный массив
    std::string getString();//возвращаем строку string
    char getCharAt(int index) const;//символ по индексу

    bool isEqual(MyString &myString);//сравнение с MyString
    void setStr(char *str2);//сеттер str_

    friend std::istream &operator>>(std::istream &in, MyString &mString);
    friend std::ostream &operator<<(std::ostream &out, const MyString &mString);
    int getLength() const;//получение длины
private:
    char *str_ = nullptr;
    int length_;
};

#endif //FILMCLASS_MYSTRING_H
