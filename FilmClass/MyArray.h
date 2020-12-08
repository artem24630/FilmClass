//
// Created by at020 on 01.12.2020.
//

#ifndef FILMCLASS_MYARRAY_H
#define FILMCLASS_MYARRAY_H

#include <iostream>
#include "Exception.h"

template<class T>
class MyArray
{
public:
    MyArray();
    ~MyArray();
    explicit MyArray(size_t size);
    MyArray(const MyArray &myArray);
    MyArray(MyArray &&myArray) noexcept;
    MyArray<T> &operator=(const MyArray &myArray);
    MyArray<T> &operator=(MyArray &&myArray) noexcept;
    T &operator[](size_t i) const;
    T &getItem(int index) const;
    int getLength() const;
    void add(T item);
    template<typename T1>
    friend std::ostream &operator<<(std::ostream &out, MyArray<T1> &array);
    void print();
private:
    T *data_;
    int length_;
    int capacity_ = 100;
};

template<class T>
MyArray<T>::MyArray()
{
    data_ = new T[capacity_];
    length_ = 0;
}
template<class T>
MyArray<T>::~MyArray()
{
    delete[] data_;
    capacity_ = 0;
    length_ = 0;
}
template<class T>
MyArray<T>::MyArray(size_t size)
{
    if (capacity_ <= size)
        capacity_ = size * 2;
    length_ = size;
    data_ = new T[capacity_];
}
template<class T>
T &MyArray<T>::operator[](size_t i) const
{
    if (i >= length_)
        throw Exception("Array index out of bounds");
    return data_[i];
}
template<class T>
void MyArray<T>::add(T item)
{
    if (length_ + 1 > capacity_) {
        T *tmp = new T[capacity_ * 2];
        for (int i = 0; i < length_; ++i) {
            tmp[i] = data_[i];
        }
        tmp[length_] = item;
        length_++;
        delete[] data_;
        data_ = tmp;
        tmp = nullptr;
    } else {
        data_[length_] = item;
        length_++;
    }
}
template<class T>
T &MyArray<T>::getItem(int index) const
{
    if (index >= length_ || index < 0)
        throw Exception("Array index out of bounds");
    return data_[index];
}
template<class T>
MyArray<T>::MyArray(const MyArray &myArray)
{
    length_ = myArray.length_;
    capacity_ = myArray.capacity_;
    data_ = new T[capacity_];
    for (int i = 0; i < length_; ++i) {
        data_[i] = myArray.data_[i];
    }
}
template<class T>
MyArray<T> &MyArray<T>::operator=(MyArray &&myArray) noexcept
{
    delete[] data_;
    length_ = myArray.length_;
    capacity_ = myArray.capacity_;
    data_ = new T[capacity_];
    for (int i = 0; i < length_; ++i) {
        data_[i] = myArray.data_[i];
    }
    return *this;
}
template<class T>
MyArray<T> &MyArray<T>::operator=(const MyArray &myArray)
{
    if (&myArray == this)
        return *this;
    delete[] data_;
    length_ = myArray.length_;
    capacity_ = myArray.capacity_;
    data_ = new T[capacity_];
    for (int i = 0; i < length_; ++i) {
        data_[i] = myArray.data_[i];
    }
    return *this;
}
template<class T>
MyArray<T>::MyArray(MyArray &&myArray) noexcept
{
    length_ = myArray.length_;
    capacity_ = myArray.capacity_;
    data_ = new T[capacity_];
    for (int i = 0; i < length_; ++i) {
        data_[i] = myArray.data_[i];
    }
}
template<class T>
void MyArray<T>::print()
{
    for (int i = 0; i < length_; ++i) {
        std::cout << data_[i] << "\n";
    }
}
template<class T>
int MyArray<T>::getLength() const
{
    return length_;
}
template<typename T1>
std::ostream &operator<<(std::ostream &out, MyArray<T1> &array)
{
    for (int i = 0; i < array.getLength(); ++i) {
        out << array[i] << "\n";
    }
    return out;
}
template<class T>
T giveMax(const MyArray<T> &array)
{
    if (array.getLength() == 0) {
        throw Exception("empty array");
    }
    T maxItem = array[0];
    for (int i = 1; i < array.getLength(); ++i) {
        if (array[i] > maxItem)
            maxItem = array[i];
    }
    return maxItem;
}
template<class T>
void sort(MyArray<T> &array, bool (*comparator)(T &f1, T &f2))
{
    int j = 0;
    for (int i = 1; i < array.getLength(); ++i) {
        T tmp = array[i];
        j = i - 1;
        while (j >= 0 && comparator(array[j], tmp)) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = tmp;
    }
}
#endif //FILMCLASS_MYARRAY_H
