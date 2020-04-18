#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

#define MAX 1000

// TODO: Implement all methods
template <typename T>
class stack {
	T* data;
	int top;
	int capacity;

public:
	stack(int size = MAX){
		this->data = new T[size];
		this->top = -1; // index of stack
		this->capacity = size;
	}

	~stack(){
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

	void pop(){ // changed returned value
		try{
			if (this->empty()){
				throw "Stack is empty, there are no elements to pop";
			} else{
				this->capacity--;
				this->top--;
				this->resize(this->capacity);
			}
		} catch(const char* msg){
			cerr << msg << endl;
		}
	}

	T peak(){ // changed returned value and changed method name because of conflict with attribute "top"
		try{
			if (this->empty()){
				throw "Stack is empty, cannot return the top element";
			} else{
				T* temp = this->data;
				temp += top;
				return *temp;
			}	
		} catch(const char* msg){
			cerr << msg << endl;
		}	
	}

	int size(){
		try{
			if (this->empty()){
				throw "Stack is empty";
			} else{
				return this->top + 1;
			}
		} catch(const char* msg){
			cerr << msg << endl;
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