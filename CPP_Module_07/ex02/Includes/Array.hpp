#pragma once

#include <stdexcept>
template<typename T>
class Array {
private:
	T* _elements;
	unsigned int _size;

public:
	// INFO: orthodox canonical
	Array();
	Array(unsigned int n);
	Array(const Array& other);
	Array&	operator=(const Array& other);
	~Array();



	// INFO: methods
	unsigned int	size() const;
	T	operator[](unsigned int index) const;
	T&	operator[](unsigned int index);

};

// INFO: orthodox canonical
// -----------------------------------------------
template<typename T>
Array<T>::Array() {
	this->_elements = new T[0];
	this->_size = 0;
}

template<typename T>
Array<T>::Array(unsigned int n) {
	this->_size = n;
	this->_elements = new T[n];
	for (unsigned int i = 0; i < n; i++) {
		this->_elements[i] = T();
	}
}


template<typename T>
Array<T>::Array(const Array& other) {
	this->_size = other._size;
	unsigned int size = other._size;
	this->_elements = new T[size];
	for (unsigned int i = 0; i < size; i++) {
		_elements[i] = other._elements[i];
	}
}

template<typename T>
Array<T>&	Array<T>::operator=(const Array& other) {
	if (this == &other) {
		return *this;
	}
	delete [] this->_elements;
	unsigned int size = other.size();
	this->_elements = new T[size];
	for (unsigned int i = 0; i < size; i++) {
		this->_elements[i] = other._elements[i];
	}
	return *this;
}

template<typename T>
Array<T>::~Array() {
	delete [] this->_elements;
}
// -----------------------------------------------






// INFO: methods
template<typename T>
unsigned int	Array<T>::size() const {
	return this->_size;
}


template<typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= this->_size) {
		throw std::out_of_range("index out of range");
	}
	return _elements[index];
}

template<typename T>
T Array<T>::operator [](unsigned int index) const {
	if (index >= this->_size) {
		throw std::out_of_range("index out of range");
	}
	return _elements[index];
}
