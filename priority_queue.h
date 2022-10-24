
// =================================================================
// File: main.cpp
// Author: Frida Bailleres Gonzalez
// Date:23/10/2022
// =================================================================

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include <string>
#include <sstream>

template <class T>
class Priority_Queue {

    private:

    	uint length;
	    uint count;
        T *data;

	    void pushUp(uint);
	    void swap(uint, uint);
        uint parent(uint) const;
	    uint right(uint) const;
	    uint left(uint) const;

    public:

         ~Priority_Queue();
        Priority_Queue(uint);
	    uint size() const;
        bool empty() const;
	    bool full() const;
	    void push(T);
	    T pop();
	    void clear();
        uint top() const;
	    std::string toString() const;
};


template <class T>
Priority_Queue<T>::Priority_Queue(uint l) {
	length = l;
	data = new T[length];
	count = 0;
}

template <class T>
Priority_Queue<T>::~Priority_Queue() {
	delete [] data;
	data = NULL;
	length = 0;
	count = 0;
}


template <class T>
bool Priority_Queue<T>::empty() const {
	return (count == 0);
}


template <class T>
bool Priority_Queue<T>::full() const {
	return (count == length);
}


template <class T>
uint Priority_Queue<T>::size() const {
	return count;
}


template <class T>
uint Priority_Queue<T>::parent(uint pos) const {
	return (pos - 1) / 2;
}


template <class T>
uint Priority_Queue<T>::left(uint pos) const {
	return (pos * 2) + 1;
}


template <class T>
uint Priority_Queue<T>::right(uint pos) const {
	return (pos * 2) + 2;
}


template <class T>
void Priority_Queue<T>::swap(uint i, uint j) {
	T aux = data[i];
	data[i] = data[j];
	data[j] = aux;
}

template <class T>
void Priority_Queue<T>::pushUp(uint pos) {
    uint le = left(pos);
    uint ri = right(pos);
    uint max = pos;

    if (le < count && data[le] > data[max]){
        max = le;
    }
    if (ri < count && data[ri] > data[max]){
        max = ri;
    }

    if(max != pos){
        swap(pos, max);
        pushUp(max);
    }
}

template <class T>
void Priority_Queue<T>::push(T val) {
	uint pos;
	if (full()){
		std::cout << "The heap is full" << std::endl;
	}

	pos = count;
	count++;
	while(pos > 0 && val > data[parent(pos)]){
		data[pos]= data[parent(pos)];
		pos = parent(pos);
	}
	data[pos] = val;
}

template <class T>
T Priority_Queue<T>::pop() {
	if (empty()){
		std::cout << "The heap is empty" << std::endl;
	}

	T aux = data[0];
	data[0] = data[--count]; 
	pushUp(0);
	return aux;
}


template <class T>
void Priority_Queue<T>::clear() {
	count = 0;
}


template <class T>
uint Priority_Queue<T>::top() const {
    if (empty()){
		std::cout << "The heap is empty" << std::endl;
	}
    else {
        return data[0];
    }
}

template <class T>
std::string Priority_Queue<T>::toString() const {
	std::stringstream aux;

	aux << "[";
	for (uint i = 0; i < count; i++) {
		if (i != 0) {
			aux << " ";
		}
	aux << data[i];
	}
	aux << "]";
	return aux.str();
}
#endif