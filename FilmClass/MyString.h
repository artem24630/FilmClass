//
// Created by at020 on 01.12.2020.
//

#ifndef FILMCLASS_MYSTRING_H
#define FILMCLASS_MYSTRING_H
#include <string>

class MyString {

public:
    explicit MyString(char *str2);//конструктор с параметром строки
    explicit MyString(std::string s);//конструктор с параметром string
    explicit MyString(int length);//конструктор с параметром длины
    MyString();//конструктор пустой
    MyString(const MyString &myString);//конструктор копирования
    //TODO конструктор переноса и оператор присваивания с переносом
    MyString &operator=(const MyString &myString);

    MyString &operator=(std::string s);//оператор присваивания string
    MyString &operator=(char* str2);//оператор присваивания char*
    MyString(MyString &&myString) noexcept ;//конструктор переноса
    MyString &operator=(MyString &&myString) noexcept; //оператор присваивания с переносом

    char &operator[](int i);//оператор []
    ~MyString(); //деструктор

    char *getCharArray();//возвращаем символьный массив
    std::string getString();//возвращаем строку string
    char getCharAt(int index) const;//символ по индексу

    bool isEqual( MyString &myString);//сравнение с MyString
    void setStr(char *str2);//сеттер str

    friend std::istream& operator>> (std::istream& in, MyString & mString);
    friend std::ostream& operator<<(std::ostream& out, MyString& mString);

    int getLength() const;//получение длины
private:
    char *str = nullptr;
    int length;

    void set_length();

};

#endif //FILMCLASS_MYSTRING_H
