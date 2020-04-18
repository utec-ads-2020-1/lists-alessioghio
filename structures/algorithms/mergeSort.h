#ifndef mergeSort_H
#define mergeSort_H

#include <iostream>
#include "../lists/node.h"

template<typename T>
void FrontBackSplit(Node<T>* root, 
                    Node<T>*& frontRef, Node<T>*& backRef) 
{ 
    Node<T>* fast; 
    Node<T>* slow; 
    slow = root; 
    fast = root->next; 
  
    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != NULL) { 
        fast = fast->next; 
        if (fast != NULL) { 
            slow = slow->next; 
            fast = fast->next; 
        } 
    } 
  
    /* 'slow' is before the midpoint in the list, so split it in two  
    at that point. */
    frontRef = root; 
    backRef = slow->next; 
    slow->next = nullptr; 
}

template<typename T>
Node<T>* SortedMerge(Node<T>*& L, Node<T>*& R){
    Node<T>* result = nullptr; 
  
    /* Base cases */
    if (L == nullptr) 
        return R; 
    else if (R == nullptr) 
        return L; 
  
    /* Pick either L or R, and recur */
    if(L->data <= R->data){ 
        result = L; 
        result->next = SortedMerge(L->next, R); 
    } 
    else{ 
        result = R;
        result->next = SortedMerge(L, R->next); 
    } 
    return result; 
} 

template<typename T>
void MergeSort(Node<T>*& rootHead){ 
    Node<T>* headRef = rootHead;
    Node<T>* L; // Left
    Node<T>* R; // Right
  
    /* Base case -- length 0 or 1 */
    if ((headRef == nullptr) || (headRef->next == nullptr)) { 
        return; 
    } 
  
    /* Split headRef into 'L' and 'R' sublists */
    FrontBackSplit(headRef, L, R); 
  
    /* Recursively sort the sublists */
    MergeSort(L); 
    MergeSort(R); 
  
    /* answer = merge the two sorted lists together */
    rootHead = SortedMerge(L, R);
} 

#endif