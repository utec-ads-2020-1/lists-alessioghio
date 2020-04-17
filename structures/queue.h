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
		this->data = new T(size);
		this->top = -1;
		this-> capacity = size;
	}

	~queue(){
		delete[] this->data;
	}   		

	void push(T value){ // added argument of type T (there was no argument)
		this->top++;
		T* temp = this->data;
		temp += top;
		*temp = value;
	}

	void pop(){
		try{
			if (this->empty()){
				throw "Queue is empty, there are no elements to pop";
			} else{
				this->capacity--;
				this->data++; // "remove" the "front" element
				this->top--;
			}
			
		} catch(const char* msg){
			cerr << msg << endl;
		}
	}

	T front(){
		try{
			if (this->empty()){
				throw "Queue is empty, cannot return the front element";
			} else{
				return *this->data;
			}
			
		} catch(const char* msg){
			cerr << msg << endl;
		}
	}

    T back(){
		try{
			if (this->empty()){
				throw "Queue is empty, cannot return the back element";
			} else{
				T* temp = this->data;
				temp += this->top;
				return *temp;
			}	
		} catch(const char* msg){
			cerr << msg << endl;
		}
	}

	int size(){
		try{
			if (this->empty()){
				throw "Queue is empty";
			} else{
				return this->top+1;
			}
			
		} catch(const char* msg){
			cerr << msg << endl;
		}
	}

	bool empty(){
		return this->top == -1; // true: is empty, false: not empty
	}
};

#endif