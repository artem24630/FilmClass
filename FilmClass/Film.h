#pragma once
#include <iostream>
#include <string>
#include <MyString.h>
class Film {
private:
	MyString name;
    MyString fioDirector;
    MyString fioScreenwriter;
	int year;
    MyString genre;
    bool isNameCorrect(const MyString& myString);
    bool isFioCorrect(const MyString& myString) const;
    bool isYearCorrect(const int& myYear) const;
    bool isGenreCorrect(const MyString& myGenre) const;
    bool isLetter(char c) const;
    bool isBigLetter(char c) const;
public:
    Film();
    Film(const MyString& name_, const MyString& fioDirector_, const MyString& fioScreenwriter_,const int& year_,
         const MyString& genre_);
    Film(const Film & film2) = default;
    Film(Film &&film2) = default;

    Film & operator=(const Film & film2) = default;
    Film & operator=(Film &&film2) = default;
    ~Film() = default;
    int operator+(const Film & film2) const;
    friend int operator-(const Film & film1, const Film & film2);
    bool operator>(const Film & film2) const;
    bool operator<(const Film & film2) const;
    friend bool operator==(const Film & film1, const Film & film2);

     MyString &getName() ;

     MyString &getFioDirector() ;

     MyString &getFioScreenwriter() ;

    int getYear() const;

    const MyString &getGenre() const;

    void print();

    static MyString* getFieldsNames();

    Film & operator++();
    friend Film operator++(Film & film,int notused);
    friend std::ostream& operator<<(std::ostream& out, Film &film);
    friend std::istream& operator>> (std::istream& in, Film & film);
};

