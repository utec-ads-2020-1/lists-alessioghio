#ifndef FORWARD_H
#define FORWARD_H

#include <iostream>
#include "list.h"
#include "iterators/forward_iterator.h"
#include "../algorithms/mergeSort.h"

using namespace std;

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
                cerr << msg << endl;
            }
        }

        T back(){
            try{
                if (this->empty()){
                    throw "Forward List is empty, cannot return back element";
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
                } else{
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
                }
            } catch(const char* msg){
                cerr << msg << endl;
            } 
        }

        void pop_back(){
            try{
                if (this->empty()){
                    throw "Forward List is empty, cannot pop back element";
                } else{
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
                }
            } catch(const char* msg){
                cerr << msg << endl;
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
                cerr << msg << endl;
            } 
        }

        bool empty(){
            return (this->nodes == 0); // true: is empty, false: not empty
        }

        int size(){
            try{
                if (this->empty()){
                    throw "Forward List is empty";
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
                    throw "Forward List is already empty";
                } else{
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
                }
            } catch(const char* msg){
                cerr << msg << endl;
            } 
        }

        void sort(){
            try{
                if (this->empty()){
                    throw "Cannot sort an empty Forward List";
                } else{
                    MergeSort(this->head);
                    this->tail = this->head;
                    while(this->tail->next!=nullptr){
                        this->tail = this->tail->next;
                    }
                }
            } catch(const char* msg){
                cerr << msg << endl;
            }
        }

        void reverse(){
            try{
                if (this->empty()){
                    throw "Cannot reverse an empty Forward List";
                } 
                else if(this->nodes == 1){
                    throw "Cannot reverse a Forward List with only one value";
                } else{
                    Node<T>* temp;
                    int iter = this->nodes-2;
                    while (iter!=-1){
                        temp = this->head;
                        for (int i = 0; i < iter; i++){ // iterate until one position before the last reversed element
                            temp = temp->next;
                        }
                        temp->next->next = temp; // Reverse "next" pointers
                        iter--;
                    }
                    // At the end reverse tail and head
                    temp = this->tail;
                    this->head->next = nullptr;
                    this->tail = this->head;
                    this->head = temp;
                }
            } catch(const char* msg){
                cerr << msg << endl;
            }
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
        void merge(ForwardList<T>& fList){
            for (int i = 0; i < fList.size(); i++){
                this->push_back(fList[i]);
            }
            fList.head = nullptr;
            fList.tail = nullptr;
        }
};

#endif