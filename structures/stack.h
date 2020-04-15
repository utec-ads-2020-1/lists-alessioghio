#ifndef STACK_H
#define STACK_H

using namespace std;

#define MAX 1000 

// TODO: Implement all methods
template <typename T>
class stack {
	T* data;
	int Top; // changed attribute to capital letter because of conflict with method
	int capacity;

public:
	stack(int size = MAX){
		this->data = new T(size);
		this->Top = -1; // index of stack
		this->capacity = size;
	}

	~stack(){
		delete[] this->data;
	}

	void push(T value){ // added argument of type T (there was no argument)
		this->Top++;
		T* temp = this->data;
		temp += Top;
		*temp = value;
	}

	T pop(){ // changed returned value
		ASSERT(this->empty()==false, "Stack is empty, there are no elements to pop");
		this->capacity--;
		T* temp = this->data;
		temp += Top;
		this->Top--;
		return *temp; 
	}

	T top(){ // changed returned value
		ASSERT(this->empty()==false, "Stack is empty, cannot return the top element");
		T* temp = this->data;
		temp += Top;
		return *temp;
	}

	int size(){
		ASSERT(this->empty()==false, "Stack is empty, cannot display size");
		return this->Top + 1;
	}

	bool empty(){
		return this->Top == -1; // true: is empty, false: not empty
	}
};

#endif