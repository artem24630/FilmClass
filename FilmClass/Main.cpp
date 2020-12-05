#include <iostream>
#include <fstream>
#include <iomanip>
#include "MyString.h"
#include "Film.h"
#include "MyArray.h"
#include <list>
int main() {
    setlocale(LC_ALL, "rus");
    MyString path;
    std::cout << "Введите путь до файла\n";
    std::cin >> path; // Вводим путь до файла с консоли

//    std::cout << path.getLength();
//    std::cout << path;
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
        MyString fioDirector;
        in >> fioDirector;
        if (!in) {
            std::cerr << "invalid input\n";
            return -1;
        }
        MyString fioScreenwriter;
        in >> fioScreenwriter;
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
            Film film(name, fioDirector, fioScreenwriter, year, genre);
            myArray.add(film);
        } catch (char *r) {
            std::cerr << r; //TODO отлавливать ошибки
            return -2;
        }
    }
    in.close();
    myArray.print();

    std::cout << "Последний вышедший фильм: ";
    Film lastFilm = giveMax(myArray);
    std::cout << lastFilm.getName() << "\n";

    sort<Film>(myArray,[](Film& f1, Film &f2)->bool{ return f1 > f2;});
   // myArray.print();
    std::ofstream out("C:\\Users\\at020\\source\\repos\\FilmClass\\FilmClass\\out.txt");
    if(out.is_open()){
        MyString * labels = Film::getFieldsNames();
        out.setf(std::ios_base::left);
        out << std::setw(51) << labels[0] << std::setw(21) << labels[1] << std::setw(21) << labels[2] << std::setw(21) << labels[3] << std::setw(6) << labels[4] << "\n";
        out << myArray;
        //Список жанров
        std::list<MyString> genres;
        for (int i = 0; i < myArray.getLength(); ++i) {
            genres.push_back(myArray[i].getGenre());
        }
        out << "\n\n\nСписок жанров:\n";
        for (MyString genre: genres){
            out << genre << "\n";
        }

        out.close();
    }else{
        std::cerr << "couldn't open the file";
    }



}
