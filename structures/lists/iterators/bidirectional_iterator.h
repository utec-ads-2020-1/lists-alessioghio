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

        BidirectionalIterator(Node<T>* listPtr){// explicit: va a generar error, ya que estás retornando uso implícito de constructores
            this->current = listPtr;
        }

        BidirectionalIterator<T> operator=(BidirectionalIterator<T>){
            // Estás creando un nuevo iterador en vez de igualarlo
            return this->current;
        }

        bool operator!=(BidirectionalIterator<T> fIterator){
            return this->current != fIterator.current;
        }

        BidirectionalIterator<T> operator++(){
            if(this->current){
                this->current = this->current->next;
                // Estás creando un nuevo iterador en vez de retornarnlo 
                return this->current;
            } else{
                throw "This iterator is not pointing to anything";
            }
        }

        BidirectionalIterator<T> operator--(){
            if(this->current){
                this->current = this->current->prev;
                // Estás creando un nuevo iterador en vez de retornarnlo 
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