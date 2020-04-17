#ifndef FORWARD_H
#define FORWARD_H

#include<iostream>
#include "list.h"
#include "iterators/forward_iterator.h"

/* 
try{
    if (this->empty()){
        throw "Forward List is empty, cannot return front element";
    }
    return this->head->data;
} catch(const char* msg){
    cerr << msg << '\n';
}
*/

// TODO: Implement all methods
template <typename T>
class ForwardList : public List<T> {
    public:
        ForwardList() : List<T>() {}

        T front(){
            try{
                if (this->empty()){
                    throw "Forward List is empty, cannot return front element";
                }
                return this->head->data;
            } catch(const char* msg){
                cerr << msg << '\n';
            }
        }

        T back(){
            try{
                if (this->empty()){
                    throw "Forward List is empty, cannot return back element";
                }
                return this->tail->data;
            } catch(const char* msg){
                cerr << msg << '\n';
            } 
        }

        void push_front(T value){ // added argument of type T (there was no argument)
            if(this->empty()){
                Node<T>* myNode = new Node<T>(value);
                this->head = myNode;
                this->tail = myNode;
            } else {
                Node<T>* myNode = new Node<T>(value);
                myNode->next = this->head;
                this->head = myNode;
            }
            this->nodes++;
        }
        
        void push_back(T value){ // added argument of type T (there was no argument)
            if(this->empty()){
                Node<T>* myNode = new Node<T>(value);
                this->head = myNode;
                this->tail = myNode;
            } else {
                Node<T>* myNode = new Node<T>(value);
                this->tail->next = myNode;
                this->tail = myNode;
            }
            this->nodes++;
        }

        void pop_front(){
            try{
                if (this->empty()){
                    throw "Forward List is empty, cannot pop front element";
                }
                if (this->nodes>1){
                    Node<T>* temp = this->head->next;
                    this->head->killSelf();
                    this->head = temp;
                } else{
                    this->head->killSelf();
                    this->head = nullptr;
                    this->tail = nullptr;
                }
                this->nodes--;
            } catch(const char* msg){
                cerr << msg << '\n';
            } 
        }
        void pop_back(){
            try{
                if (this->empty()){
                    throw "Forward List is empty, cannot pop back element";
                }
                if (this->nodes>1){
                    Node<T>* temp = this->head;
                    while (temp->next->next!=nullptr){
                    temp = temp->next;
                    }
                    this->tail->killSelf();
                    this->tail = temp;
                    this->tail->next = nullptr; // Tail next is always a nullptr
                } else{ // Only one element on list
                    this->tail->killSelf();
                    this->tail = nullptr;
                    this->head = nullptr;
                }
                this->nodes--;
            } catch(const char* msg){
                cerr << msg << '\n';
            } 
        }

        T operator[](int index){
            try{
                if (this->empty()){
                    throw "Cannot index an empty Forward List";
                } else{
                    if (index < 0){
                        throw "Index cannot be less than 0";
                    } else if(index == 0){
                        return this->head->data;
                    } else if(index == (this->nodes-1)){
                        return this->tail->data;
                    } else if(index > (this->nodes-1)){
                        throw "Index out of range";
                    } else{
                        Node<T>* temp = this->head;
                        for (int i = 0; i < index; i++){
                            temp = temp->next;
                        }
                        return temp->data;
                    }
                }  
            } catch(const char* msg){
                cerr << msg << '\n';
            } 
        }

        bool empty(){
            return (this->nodes == 0); // true: is empty, false: not empty
        }

        int size(){
            try{
                if (this->empty()){
                    throw 0;
                }
                return this->nodes;
            } catch(int e){
                std::cout << "Forward List is empty" << '\n';
            } 
        }

        void clear(){
            try{
                if (this->empty()){
                    throw 0;
                }
                Node<T>* temp = this->head;
                while (temp->next != nullptr){
                    temp = temp->next;
                    this->head->killSelf();
                    this->head = temp;
                }
                this->head->killSelf();
                this->head = nullptr;
                this->tail = nullptr;
                this->nodes = 0;
            } catch(int e){
                std::cout << "Forward List is already empty" << '\n';
            } 
        }

        void sort(){

        }

        void reverse(){

        }

        ForwardIterator<T> begin();
	    ForwardIterator<T> end();

        string name() {
            return "Forward List";
        }

        /**
         * Merges x into the list by transferring all of its elements at their respective 
         * ordered positions into the container (both containers shall already be ordered).
         * 
         * This effectively removes all the elements in x (which becomes empty), and inserts 
         * them into their ordered position within container (which expands in size by the number 
         * of elements transferred). The operation is performed without constructing nor destroying
         * any element: they are transferred, no matter whether x is an lvalue or an rvalue, 
         * or whether the value_type supports move-construction or not.
        */
        void merge(ForwardList<T>&);
};

#endif