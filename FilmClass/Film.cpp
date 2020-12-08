//
// Created by at020 on 30.11.2020.
//
#include <iomanip>
#include "Film.h"
#include "Exception.h"

Film::Film() {
    name_ = "name_";
    nameDirector_ = "director";
    nameScreenwriter_ = "screenwriter";
    year_ = 2020;
    genre_ = "drama";
}

Film::Film(const MyString &name2, const MyString &fioDirector2, const MyString &fioScreenwriter2,
           const int &year2,
           const MyString &genre2) {
    if (isNameCorrect(name2) && isFioCorrect(fioDirector2) && isFioCorrect(fioScreenwriter2) && isGenreCorrect(genre2) &&
        isYearCorrect(year2)) {
        name_ = name2;
        genre_ = genre2;
        year_ = year2;
        nameDirector_ = fioDirector2;
        nameScreenwriter_ = fioScreenwriter2;
    }
}

bool Film::operator>(const Film &film2) const {
    return year_ > film2.year_;
}

bool Film::operator<(const Film &film2) const {
    return year_ < film2.year_;
}

bool operator==(const Film &film1, const Film &film2) {
    return film1.year_ == film2.year_;
}

bool Film::isYearCorrect(const int &myYear) const {
    if (myYear >= 1895 && myYear <= 2020) {
        return true;
    } else {
        throw Exception("incorrect year_");
    }
}

int operator-(const Film &film1, const Film &film2) {
    return abs(film1.year_ - film2.year_);
}

int Film::operator+(const Film &film2) const {
    return year_ + film2.year_;
}

Film operator++(Film &film, int notused) {
    Film tmp = film;
    ++film;
    return tmp;
}

Film &Film::operator++() {
    year_++;
    return *this;
}

std::ostream &operator<<(std::ostream &out, Film &film) {
    out.setf(std::ios_base::left);
    out << std::setw(51) << film.name_ << std::setw(21) << film.nameDirector_ << std::setw(21) << film.nameScreenwriter_
        << std::setw(21)
        << film.genre_ << std::setw(6) << film.year_;
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
        throw Exception("invalid input");;
    }
    Film tmp(name_, fioDirector_, fioScreenwriter_, year_, genre_);
    film = tmp;
    return in;
}

bool Film::isNameCorrect(const MyString &myString) {
    if (myString.getLength() > 50 || myString.getLength() == 0)
        throw Exception("incorrect title of the film");
    if ((myString.getCharAt(0) >= 'A' && myString.getCharAt(0) <= 'Z') ||
        (myString.getCharAt(0) >= '0' && myString.getCharAt(0) <= '9')) {
        for (int i = 1; i < myString.getLength(); ++i) {
            char item = myString.getCharAt(i);
            if ((item == ' ' && myString.getCharAt(i + 1) != ' ') || isLetter(item) || (item >= '0' && item <= '9')) {
                continue;
            } else {
                throw Exception("incorrect title of the film");
            }
        }
    } else {
        throw Exception("incorrect title of the film");;
    }
    return true;
}

bool Film::isGenreCorrect(const MyString &myGenre) const {
    if (myGenre.getLength() > 20)
        throw Exception("incorrect genre_");
    for (int i = 0; i < myGenre.getLength(); ++i) {
        char item = myGenre.getCharAt(i);
        if (isLetter(item)) {
            continue;
        } else {
            throw Exception("incorrect genre_");
        }
    }
    return true;
}

bool Film::isFioCorrect(const MyString &myString) const {
    if (myString.getLength() > 20)
        throw Exception("incorrect surname or initials");
    char firstSymbol = myString.getCharAt(0);
    int length_ = myString.getLength();
    if (!isBigLetter(firstSymbol))
        throw Exception("incorrect surname or initials");
    if (myString.getCharAt(length_ - 1) == '.' && isBigLetter(myString.getCharAt(length_ - 2)) &&
        myString.getCharAt(length_ - 3) == '.' && isBigLetter(myString.getCharAt(length_ - 4)) &&
        myString.getCharAt(length_ - 5) == ' ') {
        for (int i = 1; i < myString.getLength() - 5; ++i) {
            if (!isLetter(myString.getCharAt(i)))
                throw Exception("incorrect surname or initials");
        }
    } else {
        throw Exception("incorrect surname or initials");
    }
    return true;
}

bool Film::isLetter(const char c) const {
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= 192 && c <= 255));
}

bool Film::isBigLetter(const char c) const {
    return (c >= 'A' && c <= 'Z' || c >= 192 && c <= 223);
}

MyString &Film::getName() {
    return name_;
}

MyString &Film::getFioDirector() {
    return nameDirector_;
}

MyString &Film::getFioScreenwriter() {
    return nameScreenwriter_;
}

int Film::getYear() const {
    return year_;
}

const MyString &Film::getGenre() const {
    return genre_;
}

void Film::print() {
    std::cout << std::setw(51) << name_ << std::setw(21) << nameDirector_ << std::setw(21) << nameScreenwriter_
              << std::setw(21)
              << genre_ << std::setw(6) << year_;
}

MyString *Film::getFieldsNames() {
    MyString *fields = new MyString[]{MyString("Film title"), MyString("Director"), MyString("Screenwriter"),
                                      MyString("Genre"), MyString("Year")};
    return fields;
}
