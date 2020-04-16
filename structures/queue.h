#ifndef QUEUE_H
#define QUEUE_H

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
		ASSERT(this->empty()==false, "Queue is empty, there are no elements to pop");
		this->capacity--;
		this->data++; // remove the "front" element
		this->top--;
	}

	T front(){
		ASSERT(this->empty()==false, "Queue is empty, cannot return the front element");
		return *this->data;
	}

    T back(){
		ASSERT(this->empty()==false, "Queue is empty, cannot return the back element");
		T* temp = this->data;
		temp += this->top;
		return *temp;
	}

	int size(){
		ASSERT(this->empty()==false, "Queue is empty, cannot display size");
		return this->top+1;
	}

	bool empty(){
		return this->top == -1; // true: is empty, false: not empty
	}
};

#endif