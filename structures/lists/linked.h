#ifndef LINKED_H
#define LINKED_H

#include <iostream>
#include "list.h"
#include "iterators/bidirectional_iterator.h"
#include "../algorithms/mergeSort.h"


// TODO: Implement all methods
template <typename T>
class LinkedList : public List<T> {
    private:
        Node<T>* sentinel;
    public:
        LinkedList() : List<T>() {
            sentinel = new Node<T>();
        }

        // Similar a Forward List
        ~LinkedList(){ // Similar to clear
            if (!this->empty()){ // list is not empty
                this->head->prev = nullptr;
                this->tail->next = nullptr;
                Node<T>* temp = this->head;
                while (temp->next != nullptr){
                    temp = temp->next;
                    this->head->killSelf();
                    this->head = temp;
                }
                this->head->killSelf();
                delete this->head;
                delete this->tail;
                delete this->sentinel;
            }
        }

        T front(){
            if (this->empty()){
                throw "Linked List is empty, cannot return front element";
            }
            return this->head->data;
        }
        
        T back(){
            if (this->empty()){
                throw "Linked List is empty, cannot return back element";
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
                this->head->prev = myNode;
                this->head = myNode;
            }
            this->head->prev = sentinel;
            this->tail->next = sentinel;
            sentinel->next = this->head;
            sentinel->prev = this->tail;
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
            this->head->prev = sentinel;
            this->tail->next = sentinel;
            sentinel->next = this->head;
            sentinel->prev = this->tail;
            this->nodes++;
        }

        void pop_front(){
            if (!this->empty()){
                this->head->prev = nullptr;
                this->tail->next = nullptr;
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
                this->head->prev = sentinel;
                this->tail->next = sentinel;
                sentinel->next = this->head;
                sentinel->prev = this->tail;
                this->nodes--;
            }
        }
        
        void pop_back(){
            if (!this->empty()){
                // Esto  ya  debería estar así, está sobrando
                this->head->prev = nullptr;
                this->tail->next = nullptr;
                ///////////////////////////
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
                this->head->prev = sentinel;
                this->tail->next = sentinel;
                sentinel->next = this->head;
                sentinel->prev = this->tail;
                this->nodes--;
            }
        }
        
        T operator[](int index){ // added int argument (there was no argument)
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
        }

        bool empty(){
            return (this->nodes == 0); // true: is empty, false: not empty
        }
        
        int size(){
            return this->nodes;
        }
        
        void clear(){
            if (!this->empty()){
                this->head->prev = nullptr;
                this->tail->next = nullptr;
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
                sentinel->next = this->head;
                sentinel->prev = this->tail;
                this->nodes = 0;
            }
        }
        
        void sort(){
            if (!this->empty() || this->nodes != 1){
                this->head->prev = nullptr;
                this->tail->next = nullptr;
                MergeSort(this->head);
                Node<T>* temp = this->head;
                while(temp->next!=nullptr){
                    this->tail = temp->next;
                    this->tail->prev = temp;
                    temp = temp->next;
                }
            }
            this->head->prev = sentinel;
            this->tail->next = sentinel;
            sentinel->next = this->head;
            sentinel->prev = this->tail;
        }
        
        void reverse(){
            if (!this->empty() || this->nodes != 1){
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
                this->head->prev = sentinel;
                this->tail->next = sentinel;
                sentinel->next = this->head;
                sentinel->prev = this->tail;
            }
        }

        BidirectionalIterator<T> begin(){
            return BidirectionalIterator<T>(sentinel->next);
        }

	    BidirectionalIterator<T> end(){
            return BidirectionalIterator<T>(sentinel);
        }

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
            if(!lList.empty()){
                if(this->empty()){
                    this->head = lList.head;
                    this->tail = lList.tail;
                } else{
                    this->tail->next = lList.head;
                    lList.head->prev = this->tail;
                    this->tail = lList.tail;
                }
                lList.head = nullptr;
                lList.tail = nullptr;
                this->nodes += lList.nodes;
                lList.nodes = 0;
                sentinel->next = this->head;
                sentinel->prev = this->tail;
            }
        }
};

#endif