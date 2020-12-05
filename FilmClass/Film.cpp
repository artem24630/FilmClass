//
// Created by at020 on 30.11.2020.
//
#include <iomanip>
#include "Film.h"

Film::Film() {
    name = "name";
    fioDirector = "director";
    fioScreenwriter = "screenwriter";
    year = 2020;
    genre = "drama";
}

Film::Film(const MyString &name_, const MyString &fioDirector_, const MyString &fioScreenwriter_,
           const int &year_,
           const MyString &genre_) {
    if (isGenreCorrect(genre_) && isNameCorrect(name_) && isFioCorrect(fioScreenwriter_) &&
        isFioCorrect(fioDirector_) && isYearCorrect(year_)) {
        name = name_;
        genre = genre_;
        year = year_;
        fioDirector = fioDirector_;
        fioScreenwriter = fioScreenwriter_;
    } else {
        throw "error: invalid input";
    }
}

bool Film::operator>(const Film &film2) const {
    return year > film2.year;
}

bool Film::operator<(const Film &film2) const {
    return year < film2.year;
}

bool operator==(const Film &film1, const Film &film2) {
    return film1.year == film2.year;
}

bool Film::isYearCorrect(const int &myYear) const{
    if (myYear >= 1895 && myYear <= 2020) {
        return true;
    } else {
        throw "incorrect year";
    }
}

int operator-(const Film &film1, const Film &film2) {
    return abs(film1.year - film2.year);
}

int Film::operator+(const Film &film2) const {
    return year + film2.year;
}

Film operator++(Film &film, int notused) {
    Film tmp = film;
    ++film;
    return tmp;
}

Film &Film::operator++() {
    year++;
    return *this;
}

std::ostream &operator<<(std::ostream &out, Film &film) {
    out.setf(std::ios_base::left);
    out <<std::setw(51) << film.name << std::setw(21)  << film.fioDirector<< std::setw(21) << film.fioScreenwriter<< std::setw(21)
        << film.genre << std::setw(6) <<film.year;
    return out;
}

std::istream &operator>>(std::istream &in, Film &film) {
    MyString name_, fioDirector_, fioScreenwriter_, genre_;
    int year_;
    in >> name_;
    in >> fioDirector_;
    in >> fioScreenwriter_;
    in >> year_;
    in >> genre_;
    if (!in) {
        throw "exception";
    }
    Film tmp(name_, fioDirector_, fioScreenwriter_, year_, genre_);
    film = tmp;
    return in;
}

bool Film::isNameCorrect(const MyString &myString) {
    if (myString.getLength() > 50 || myString.getLength() == 0)
        throw "incorrect title of the film";
    if ((myString.getCharAt(0) >= 'A' && myString.getCharAt(0) <= 'Z') ||
        (myString.getCharAt(0) >= '0' && myString.getCharAt(0) <= '9') ||
        (myString.getCharAt(0) >= 192 && myString.getCharAt(0) <= 223)) {
        for (int i = 1; i < myString.getLength(); ++i) {
            char item = myString.getCharAt(i);
            if ((item == ' ' && myString.getCharAt(i + 1) != ' ') || isLetter(item) || (item >= '0' && item <= '9')) {
                continue;
            } else {
                throw "incorrect title of the film";
            }
        }
    } else {
        throw "incorrect title of the film";
    }
    return true;
}

bool Film::isGenreCorrect(const MyString &myGenre) const{
    if (myGenre.getLength() > 20)
        throw "incorrect genre";
    for (int i = 0; i < myGenre.getLength(); ++i) {
        char item = myGenre.getCharAt(i);

        if (isLetter(item)) {
            continue;
        } else {
            throw "incorrect genre";
        }
    }
    return true;
}

bool Film::isFioCorrect(const MyString &myString) const{
    if(myString.getLength() > 20)
        throw "incorrect surname or initials";
    char firstSymbol = myString.getCharAt(0);
    int length_ = myString.getLength();
    if (!isBigLetter(firstSymbol))
        throw "incorrect surname or initials";
    if (myString.getCharAt(length_ - 1) == '.' && isBigLetter(myString.getCharAt(length_ - 2)) &&
        myString.getCharAt(length_ - 3) == '.' && isBigLetter(myString.getCharAt(length_ - 4)) &&
        myString.getCharAt(length_ - 5) == ' ') {
        for (int i = 1; i < myString.getLength() - 5; ++i) {
            if(!isLetter(myString.getCharAt(i)))
                throw "incorrect surname or initials";
        }
    }else{
        throw "incorrect surname or initials";
    }

    return true;
}

bool Film::isLetter(const char c) const{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= 192 && c <= 255));
}

bool Film::isBigLetter(const char c) const {
    return (c >= 'A' && c <= 'Z' || c >= 192 && c <= 223);
}

 MyString &Film::getName()  {
    return name;
}

 MyString &Film::getFioDirector()  {
    return fioDirector;
}

 MyString &Film::getFioScreenwriter()  {
    return fioScreenwriter;
}

int Film::getYear() const {
    return year;
}

const MyString &Film::getGenre() const {
    return genre;
}

void Film::print() {
    std::cout<< std::setw(51) <<name<< std::setw(21)  << fioDirector<< std::setw(21) << fioScreenwriter<< std::setw(21)
       << genre << std::setw(6) << year;
}

MyString *Film::getFieldsNames() {
    MyString* fields = new MyString[]{MyString("Film title"), MyString("Director"), MyString("Screenwriter"), MyString("Genre"), MyString("Year")};
    return fields;
}
