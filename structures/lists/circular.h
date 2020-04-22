#ifndef CIRCULAR_H
#define CIRCULAR_H

#include <iostream>
#include "list.h"
#include "iterators/bidirectional_iterator.h"
#include "../algorithms/mergeSort.h"

// TODO: Implement all methods
template <typename T>
class CircularLinkedList : public List<T> {
    public:
        CircularLinkedList() : List<T>() {}

        ~CircularLinkedList(){
            if (!this->empty()){ // list is not empty
                Node<T>* temp = this->head;
                this->tail->next = nullptr;
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
            if (this->empty()){
                throw "Circular Linked List is empty, cannot return front element";
            }
            return this->head->data;
        }

        T back(){
            if (this->empty()){
                throw "Circular Linked List is empty, cannot return back element";
            } else {
                return this->tail->data;
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
                myNode->prev = this->tail;
                this->head->prev = myNode;
                this->tail->next = myNode;
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
                myNode->next = this->head;
                this->head->prev = myNode;
                this->tail = myNode;
            }
            this->nodes++;
        }

        void pop_front(){
            if (this->empty()){
                throw "Circular Linked List is empty, cannot pop front element";
            } else{
                if (this->nodes>1){
                    Node<T>* temp = this->head->next;
                    this->head->killSelf();
                    this->head = temp;
                    this->head->prev = this->tail;
                    this->tail->next = this->head;
                } else{
                    this->head->killSelf();
                    this->head = nullptr;
                    this->tail = nullptr;
                }
                this->nodes--;
            }
        }

        void pop_back(){
            if (this->empty()){
                throw "Circular Linked List is empty, cannot pop back element";
            } else{
                if (this->nodes>1){
                    Node<T>* temp = this->tail->prev;
                    this->tail->killSelf();
                    this->tail = temp;
                    this->tail->next = this->head;
                    this->head->prev = this->tail;
                } else{ // Only one element on list
                    this->tail->killSelf();
                    this->tail = nullptr;
                    this->head = nullptr;
                }
                this->nodes--;
            }
        }

        T operator[](int index){ // added int argument (there was no argument)
            if (this->empty()){
                throw "Cannot index an empty Circular Linked List";
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
        }

        bool empty(){
            return (this->nodes == 0); // true: is empty, false: not empty
        }

        int size(){
            if (this->empty()){
                throw "Circular Linked List is empty";
            } else{
                return this->nodes;
            }
        }

        void clear(){
            if (this->empty()){
                throw "Circular Linked List is already empty";
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
        }

        void sort(){
            if (this->empty()){
                throw "Cannot sort an empty Circular Linked List";
            } else if(this->nodes == 1){
                throw "Circular Linked List only has one element, sort aborted";
            } else{
                this->head->prev = nullptr;
                this->tail->next = nullptr;
                MergeSort(this->head);
                Node<T>* temp = this->head;
                while(temp->next!=nullptr){
                    this->tail = temp->next;
                    this->tail->prev = temp;
                    temp = temp->next;
                }
                this->head->prev = this->tail;
                this->tail->next = this->head;
            }
        }

        void reverse(){
            if (this->empty()){
                throw "Cannot reverse an empty Circular Linked List";
            } 
            else if(this->nodes == 1){
                throw "Circular Linked List only has one element, reverse aborted";
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
        }

        BidirectionalIterator<T> begin(){
            BidirectionalIterator<T> biIterBegin = this->head;
            return biIterBegin;
        }

	    BidirectionalIterator<T> end(){
            BidirectionalIterator<T> biIterBegin = this->head;
            return biIterBegin;
        }

        string name() {
            return "Circular Linked List";
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
        void merge(CircularLinkedList<T>& cList){
            if (this->empty()){
                throw "This Circular Linked List is empty, merge aborted";
            } else if(cList.empty()){
                throw "Circular Linked List to be merged is empty, merge aborted";
            } else{
                for (int i = 0; i < cList.size(); i++){
                    this->tail->next = cList.head;
                    cList.head->prev = this->tail;
                    this->tail = cList.head;
                    cList.head = cList.head->next;
                }
                cList.head = nullptr;
                cList.tail = nullptr;
                this->tail->next = this->head;
                this->head->prev = this->tail;
                this->nodes += cList.nodes;
                cList.nodes = 0;
            }
        }
};

#endif