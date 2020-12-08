#include <iostream>
#include <fstream>
#include <iomanip>
#include "MyString.h"
#include "Film.h"
#include "MyArray.h"
#include "Exception.h"
#include <list>

int main()
{
    setlocale(LC_ALL, "rus");
    MyString path;
    std::cout << "Write path to the file:\n";
    std::cin >> path; // Вводим путь до файла с консоли
    std::ifstream in(path.getString());
    if (!in.is_open()) {
        std::cerr << "the file doesn't exist\n";
        return -1;
    }
    MyArray<Film> myArray;
    while (!in.eof()) {
        /*
        Формат ввода:
         Название
         Фио режиссера
         Фио сценариста
         жанр
         год
        */
        MyString name;
        in >> name;
        if (!in) {
            std::cerr << "invalid input\n";
            return -1;
        }
        MyString nameDirector;
        in >> nameDirector;
        if (!in) {
            std::cerr << "invalid input\n";
            return -1;
        }
        MyString nameScreenwriter;
        in >> nameScreenwriter;
        if (!in) {
            std::cerr << "invalid input\n";
            return -1;
        }
        MyString genre;
        in >> genre;
        if (!in) {
            std::cerr << "invalid input\n";
            return -1;
        }
        int year;
        in >> year;
        if (!in) {
            std::cerr << "invalid input\n";
            return -1;
        }
        in.ignore(1000, '\n');
        try {
            Film film(name, nameDirector, nameScreenwriter, year, genre);
            myArray.add(film);
        } catch (Exception &e) {
            std::cerr << e.get_msg() << ": " << name << "\n";
            std::cerr << "Skip this film\n";
        }
    }
    in.close();
    sort<Film>(myArray, [](Film &f1, Film &f2) -> bool { return f1 > f2; });
    std::ofstream out("C:\\Users\\at020\\source\\repos\\FilmClass\\FilmClass\\out.txt");
    if (out.is_open()) {
        MyString *labels = Film::getFieldsNames();
        out.setf(std::ios_base::left);
        out << std::setw(51) << labels[0] << std::setw(21) << labels[1] << std::setw(21) << labels[2] << std::setw(21)
            << labels[3] << std::setw(6) << labels[4] << "\n";
        out << myArray;
        out << "\n\n";
        //Последний вышедший фильм
        out << "The newest film:\n";
        Film lastFilm = giveMax(myArray);
        out << lastFilm << "\n\n";
        //Список жанров
        std::list<MyString> genres;
        for (int i = 0; i < myArray.getLength(); ++i) {
            genres.push_back(myArray[i].getGenre());
        }
        out << "List of genres:\n";
        for (MyString genre: genres) {
            out << genre << "\n";
        }
        out.close();
    } else {
        std::cerr << "couldn't open the file\n";
    }
    return 0;
}
