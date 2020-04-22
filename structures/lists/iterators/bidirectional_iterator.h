#ifndef BIDIRECTIONAL_ITERATOR_H
#define BIDIRECTIONAL_ITERATOR_H

#include "../node.h"

// TODO: Implement all methods
template <typename T> 
class BidirectionalIterator {
    private:
        Node<T> *current;

    public:
        BidirectionalIterator(){
            this->current = nullptr;
        }

        BidirectionalIterator(Node<T>* listPtr){
            this->current = listPtr;
        }

        BidirectionalIterator<T> operator=(BidirectionalIterator<T>){
            return this->current;
        }

        bool operator!=(BidirectionalIterator<T> fIterator){
            return this->current != fIterator.current;
        }

        BidirectionalIterator<T> operator++(){
            if(this->current){
                this->current = this->current->next;
                return this->current;
            } else{
                throw "This iterator is not pointing to anything";
            }
        }

        BidirectionalIterator<T> operator--(){
            if(this->current){
                this->current = this->current->prev;
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