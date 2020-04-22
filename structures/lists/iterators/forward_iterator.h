#ifndef FORWARD_ITERATOR_H
#define FORWARD_ITERATOR_H

#include "../node.h"

// TODO: Implement all methods
template <typename T> 
class ForwardIterator {
    private:
        Node<T> *current;

    public:
        ForwardIterator(){
            this->current = nullptr;
        }

        ForwardIterator(Node<T>* listPtr){
            this->current = listPtr;
        }

        ForwardIterator<T> operator=(ForwardIterator<T>){
            return this->current;
        }

        bool operator!=(ForwardIterator<T> fIterator){
            return this->current != fIterator.current;
        }

        ForwardIterator<T> operator++(){
            if(this->current){
                this->current = this->current->next;
                return this->current;
            } else{
                throw "This iterator is not pointing to anything";
            }
            
        }

        T operator*(){
            if(this->current){
                return this->current->data;
            } else{
                throw "This iterator is not pointing to anything";
            }
        }
};

#endif