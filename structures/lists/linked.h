#ifndef LINKED_H
#define LINKED_H

#include <iostream>
#include "list.h"
#include "iterators/bidirectional_iterator.h"
#include "../algorithms/mergeSort.h"


// TODO: Implement all methods
template <typename T>
class LinkedList : public List<T> {
    public:
        LinkedList() : List<T>() {}

        ~LinkedList(){ // Similar to clear
            if (!this->empty()){ // list is not empty
                Node<T>* temp = this->head;
                while (temp->next != nullptr){
                    temp = temp->next;
                    this->head->killSelf();
                    this->head = temp;
                }
                this->head->killSelf();
                delete this->head;
                delete this->tail;
            }
        }

        T front(){
            try{
                if (this->empty()){
                    throw "Linked List is empty, cannot return front element";
                }
                return this->head->data;
            } catch(const char* msg){
                cerr << msg << endl;
            }
        }
        
        T back(){
            try{
                if (this->empty()){
                    throw "Linked List is empty, cannot return back element";
                } else {
                    return this->tail->data;
                }
            } catch(const char* msg){
                cerr << msg << endl;
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
                this->head->prev = myNode;
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
                myNode->prev = this->tail;
                this->tail = myNode;
            }
            this->nodes++;
        }

        void pop_front(){
            try{
                if (this->empty()){
                    throw "Linked List is empty, cannot pop front element";
                } else{
                    if (this->nodes>1){
                        Node<T>* temp = this->head->next;
                        this->head->killSelf();
                        this->head = temp;
                        this->head->prev = nullptr;
                    } else{
                        this->head->killSelf();
                        this->head = nullptr;
                        this->tail = nullptr;
                    }
                    this->nodes--;
                }
            } catch(const char* msg){
                cerr << msg << endl;
            }
        }
        
        void pop_back(){
            try{
                if (this->empty()){
                    throw "Linked List is empty, cannot pop back element";
                } else{
                    if (this->nodes>1){
                        Node<T>* temp = this->tail->prev;
                        this->tail->killSelf();
                        this->tail = temp;
                        this->tail->next = nullptr; // Tail next is always a nullptr
                    } else{ // Only one element on list
                        this->tail->killSelf();
                        this->tail = nullptr;
                        this->head = nullptr;
                    }
                    this->nodes--;
                }
            } catch(const char* msg){
                cerr << msg << endl;
            } 
        }
        
        T operator[](int index){ // added int argument (there was no argument)
            try{
                if (this->empty()){
                    throw "Cannot index an empty Linked List";
                } else{
                    if (index < 0){
                        throw "Index cannot be less than 0";
                    } else if(index == 0){ // return first element
                        return this->head->data;
                    } else if(index == (this->nodes-1)){ // return last element
                        return this->tail->data;
                    } else if(index > (this->nodes-1)){
                        throw "Index out of range";
                    } else if(index > 0 && index < this->nodes/2){ // index is ont he first half
                        Node<T>* temp = this->head;
                        for (int i = 0; i < index; i++){
                            temp = temp->next;
                        }
                        return temp->data;
                    } else{ // index is on the second half
                        Node<T>* temp = this->tail;
                        for (int i = this->nodes-1; i > index; i--){
                            temp = temp->prev;
                        }
                        return temp->data;
                    }
                }  
            } catch(const char* msg){
                cerr << msg << endl;
            }
        }

        bool empty(){
            return (this->nodes == 0); // true: is empty, false: not empty
        }
        
        int size(){
            try{
                if (this->empty()){
                    throw "Linked List is empty";
                } else{
                    return this->nodes;
                }
            } catch(const char* msg){
                cerr << msg << endl;
            }
        }
        
        void clear(){
            try{
                if (this->empty()){
                    throw "Linked List is already empty";
                } else{
                    Node<T>* temp = this->head;
                    while (temp->next != nullptr){
                        temp = temp->next;
                        this->head->killSelf();
                        this->head = temp;
                    }
                    this->head->killSelf();
                    // Next lines allow to use the structure
                    this->head = nullptr;
                    this->tail = nullptr;
                    this->nodes = 0;
                }
            } catch(const char* msg){
                cerr << msg << endl;
            } 
        }
        
        void sort(){
            try{
                if (this->empty()){
                    throw "Cannot sort an empty Linked List";
                } else if(this->nodes == 1){
                    throw "Linked List only has one element, sort aborted";
                } else{
                    MergeSort(this->head);
                    this->head->prev = nullptr;
                    Node<T>* temp = this->head;
                    while(temp->next!=nullptr){
                        this->tail = temp->next;
                        this->tail->prev = temp;
                        temp = temp->next;
                    }
                }
            } catch(const char* msg){
                cerr << msg << endl;
            }
        }
        
        void reverse(){
            try{
                if (this->empty()){
                    throw "Cannot reverse an empty Linked List";
                } 
                else if(this->nodes == 1){
                    throw "Linked List only has one element, reverse aborted";
                } else{
                    Node<T>* temp,* tempN;
                    temp = this->head;
                    for (int i = 0; i < this->nodes; i++){ // iterate until one position before the last reversed element
                        tempN = temp->next;
                        temp->next = temp->prev;
                        temp->prev = tempN;
                        temp = temp->prev; // previous node is now the new next
                    }
                    // At the end reverse tail and head
                    temp = this->tail;
                    this->tail = this->head;
                    this->head = temp;
                }
            } catch(const char* msg){
                cerr << msg << endl;
            }
        }

        BidirectionalIterator<T> begin();
	    BidirectionalIterator<T> end();

        string name() {
            return "Linked List";
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
        void merge(LinkedList<T>& lList){
            try{
                if (this->empty() || lList.empty()){
                    throw "Linked List to be merged is empty, merge aborted";
                } else{
                    for (int i = 0; i < lList.size(); i++){
                        this->tail->next = lList.head;
                        lList.head->prev = this->tail;
                        this->tail = lList.head;
                        lList.head = lList.head->next;
                    }
                    lList.tail = nullptr;
                    this->nodes += lList.nodes;
                    lList.nodes = 0;
                }
            } catch(const char* msg){
                cerr << msg << endl;
            }
        }
};

#endif