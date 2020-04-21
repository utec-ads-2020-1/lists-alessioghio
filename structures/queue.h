#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

using namespace std;

#define MAX 1000 

// TODO: Implement all methods
template <typename T>
class queue {
	T* data;
	int top;
	int capacity;

public:
	queue(int size = MAX){
		this->data = new T[size];
		this->top = -1;
		this-> capacity = size;
	}

	~queue(){
		delete[] this->data;
	}   		

	void push(T value){ // added argument of type T (there was no argument)
		if(this->capacity-1==this->top){ // queue is full
			this->resize(this->capacity*2);
		}
		this->top++;
		T* temp = this->data;
		temp += top;
		*temp = value;
	}

	void pop(){
		if (this->empty()){
			throw "Queue is empty, there are no elements to pop";
		} else{
			this->capacity--;
			this->data++; // "remove" the "front" element
			this->top--;
			this->resize(this->capacity);
		}
	}

	T front(){
		if (this->empty()){
			throw "Queue is empty, cannot return the front element";
		} else{
			return *this->data;
		}
	}

    T back(){
		if (this->empty()){
			throw "Queue is empty, cannot return the back element";
		} else{
			T* temp = this->data;
			temp += this->top;
			return *temp;
		}
	}

	int size(){
		if (this->empty()){
			throw "Queue is empty";
		} else{
			return this->top+1;
		}
	}

	bool empty(){
		return this->top == -1; // true: is empty, false: not empty
	}

	void resize(int newMax){
		T* temp = new T[newMax];
		int iter;
		iter = (newMax<this->capacity) ? newMax : this->capacity;
		for (int i = 0; i < iter; i++){
			temp[i] = this->data[i];
		}
		delete[] this->data;
		this->data = temp;
		this->capacity = newMax;
	}
};

#endif