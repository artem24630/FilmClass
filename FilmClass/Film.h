#pragma once

#include <iostream>
#include <string>
#include <MyString.h>

class Film
{
public:
    Film();
    Film(const MyString &name2, const MyString &fioDirector2, const MyString &fioScreenwriter2, const int &year2,
         const MyString &genre2);
    Film(const Film &film2) = default;
    Film(Film &&film2) = default;
    Film &operator=(const Film &film2) = default;
    Film &operator=(Film &&film2) = default;
    ~Film() = default;
    int operator+(const Film &film2) const;
    friend int operator-(const Film &film1, const Film &film2);
    bool operator>(const Film &film2) const;
    bool operator<(const Film &film2) const;
    friend bool operator==(const Film &film1, const Film &film2);
    MyString &getName();
    MyString &getFioDirector();
    MyString &getFioScreenwriter();
    int getYear() const;
    const MyString &getGenre() const;
    void print();
    static MyString *getFieldsNames();
    Film &operator++();
    friend Film operator++(Film &film, int notused);
    friend std::ostream &operator<<(std::ostream &out, Film &film);
    friend std::istream &operator>>(std::istream &in, Film &film);
private:
    MyString name_;
    MyString nameDirector_;
    MyString nameScreenwriter_;
    int year_;
    MyString genre_;
    bool isNameCorrect(const MyString &myString);
    bool isFioCorrect(const MyString &myString) const;
    bool isYearCorrect(const int &myYear) const;
    bool isGenreCorrect(const MyString &myGenre) const;
    bool isLetter(char c) const;
    bool isBigLetter(char c) const;
};

