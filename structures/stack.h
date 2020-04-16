#ifndef STACK_H
#define STACK_H

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
		this->data = new T(size);
		this->top = -1; // index of stack
		this->capacity = size;
	}

	~stack(){
		delete[] this->data;
	}

	void push(T value){ // added argument of type T (there was no argument)
		this->top++;
		T* temp = this->data;
		temp += top;
		*temp = value;
	}

	void pop(){ // changed returned value
		ASSERT(this->empty()==false, "Stack is empty, there are no elements to pop");
		this->capacity--;
		this->top--;
	}

	T peak(){ // changed returned value and changed method name because of conflict with attribute "top"
		ASSERT(this->empty()==false, "Stack is empty, cannot return the top element");
		T* temp = this->data;
		temp += top;
		return *temp;
	}

	int size(){
		ASSERT(this->empty()==false, "Stack is empty, cannot display size");
		return this->top + 1;
	}

	bool empty(){
		return this->top == -1; // true: is empty, false: not empty
	}
};

#endif