//
// Created by denys on 07.07.19.
//

#pragma once

template <typename T>
class Array {
public:
    Array();
    Array(unsigned int n);
    Array(const Array &old_array);

    std::size_t size();
    Array &operator=(const Array &old_array);
    T     &operator[](std::size_t position);

    ~Array();

private:
    std::size_t _size{};
    T           *_array;
};

template<typename T>
Array<T>::Array() {
    this->_size = 0;
    this->_array = new T[0];
    std::cout << "Array created, size = " << this->_size << " array_addres = " << this->_array << std::endl;
}

template<typename T>
std::size_t Array<T>::size() {
    return this->_size;
}

template<typename T>
Array<T>::Array(unsigned int n) {
    this->_size = n;
    this->_array = new T[n];
    std::cout << "Array created, size = " << this->_size << " array_addres = " << this->_array << std::endl;
}

template<typename T>
Array<T>::~Array() {
    delete[] this->_array;
    std::cout << "Array deleted, size = " << this->_size << " array_addres = " << this->_array << std::endl;
}

template<typename T>
Array<T> &Array<T>::operator=(const Array &old_array) {
    std::cout << "Array copied from, array_addres = " << old_array._array << std::endl;
    std::cout << "Array copied to, array_addres = " << this->_array << std::endl;

    delete [] this->_array;
    this->_size = old_array._size;
    this->_array = new T[this->_size];

    for (std::size_t i = 0; i < this->_size; ++i) {
        this->_array[i] = old_array._array[i];
    }
    return *this;
}

template<typename T>
Array<T>::Array(const Array &old_array) {
    this->_size = old_array._size;
    this->_array = new T[this->_size];

    for (std::size_t i = 0; i < this->_size; ++i) {
        this->_array[i] = old_array._array[i];
    }
}

template<typename T>
T &Array<T>::operator[](std::size_t position) {
    if (this->_size <= position)
        throw std::out_of_range(std::to_string(position) + " out of range");
    return this->_array[position];
}
