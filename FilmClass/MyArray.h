//
// Created by at020 on 01.12.2020.
//

#ifndef FILMCLASS_MYARRAY_H
#define FILMCLASS_MYARRAY_H

#include <iostream>

template<class T>
class MyArray {
public:
    MyArray();

    ~MyArray();

    explicit MyArray(int size);

    MyArray(const MyArray &myArray);

    MyArray(MyArray &&myArray) noexcept;

    MyArray<T> &operator=(const MyArray &myArray);

    MyArray<T> &operator=(MyArray &&myArray) noexcept;

    T &operator[](int i) const;

    T &getItem(int index) const;

    int getLength() const;

    void add(T item);

    template <typename T1> friend std::ostream &operator<< (std::ostream &out,  MyArray<T1> & array);

    void print();

private:
    T *data;
    int length;
    int capacity = 100;
};

template<class T>
MyArray<T>::MyArray() {
    data = new T[capacity];
    length = 0;
}

template<class T>
MyArray<T>::~MyArray() {
    delete[] data;
    capacity = 0;
    length = 0;
}

template<class T>
MyArray<T>::MyArray(int size) {
    if (capacity <= size)
        capacity = size * 2;
    length = size;
    data = new T[capacity];
}

template<class T>
T &MyArray<T>::operator[](int i) const {
    if (i >= length || i < 0)
        throw "out of index array";
    return data[i];
}

template<class T>
void MyArray<T>::add(T item) {
    if (length + 1 > capacity) {
        T *tmp = new T[capacity * 2];
        for (int i = 0; i < length; ++i) {
            tmp[i] = data[i];
        }
        tmp[length] = item;
        length++;
        delete[] data;
        data = tmp;
        tmp = nullptr;
    } else {
        data[length] = item;
        length++;
    }
}

template<class T>
T &MyArray<T>::getItem(int index) const {
    if (i >= size || i < 0)
        throw "out of index array";
    return data[i];
}

template<class T>
MyArray<T>::MyArray(const MyArray &myArray) {
    length = myArray.length;
    capacity = myArray.capacity;
    data = new T[capacity];
    for (int i = 0; i < length; ++i) {
        data[i] = myArray.data[i];
    }
}

template<class T>
MyArray<T> &MyArray<T>::operator=(MyArray &&myArray) noexcept {
    delete[] data;
    length = myArray.length;
    capacity = myArray.capacity;
    data = new T[capacity];
    for (int i = 0; i < length; ++i) {
        data[i] = myArray.data[i];
    }
    return *this;
}

template<class T>
MyArray<T> & MyArray<T>::operator=(const MyArray &myArray) {
    if (&myArray == this)
        return *this;
    delete[] data;
    length = myArray.length;
    capacity = myArray.capacity;
    data = new T[capacity];
    for (int i = 0; i < length; ++i) {
        data[i] = myArray.data[i];
    }
    return *this;
}

template<class T>
MyArray<T>::MyArray(MyArray &&myArray) noexcept {
    length = myArray.length;
    capacity = myArray.capacity;
    data = new T[capacity];
    for (int i = 0; i < length; ++i) {
        data[i] = myArray.data[i];
    }
}

//template<class T>
//std::ostream &MyArray<T>::operator<<(std::ostream &out) {
//    for (int i = 0; i < length; ++i) {
//        out << data[i] << "\n";
//    }
//    return out;
//}

template<class T>
void MyArray<T>::print() {
    for (int i = 0; i < length; ++i) {
        std::cout << data[i] << "\n";
    }
}

template<class T>
int MyArray<T>::getLength() const {
    return length;
}
template <typename T1>
std::ostream &operator<< (std::ostream &out, MyArray<T1> & array) {
    for (int i = 0; i < array.getLength(); ++i) {
        out << array[i] << "\n";
    }
    return out;
}

template<class T>
T giveMax(const MyArray<T> &array) {
    if(array.getLength()==0){throw "empty array";}
    T maxItem = array[0];
    for (int i = 1; i < array.getLength(); ++i) {
        if(array[i] > maxItem)
            maxItem = array[i];
    }
    return maxItem;
}

template<class T>
void sort(MyArray<T> &array, bool (*comparator)(T &f1, T &f2)){
    for (int i = 0; i < array.getLength() - 1; ++i) {
        T tmp = array[i];
        int index = 0;
        for (int j = i; j < array.getLength(); ++j) {
            if(comparator(tmp, array[j])) {
                tmp = array[j];
                index = j;
            }
        }
        array[index] = array[i];
        array[i] = tmp;
    }
}
#endif //FILMCLASS_MYARRAY_H
