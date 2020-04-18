#include <iostream>
#include <string>
#include "test/tester.h"
#include "structures/stack.h"
#include "structures/queue.h"
#include "structures/lists/list.h"
#include "structures/lists/forward.h"
#include "structures/lists/node.h"
#include "structures/algorithms/mergeSort.h"
#include "structures/lists/linked.h"

using namespace std;


int main(int argc, char *argv[]) {
    
    /* stack<int> myStack(2);

    myStack.push(1);
    myStack.push(2);
    int topVal = myStack.peak();
    myStack.push(3);
    int size = myStack.size();
    myStack.pop();
    size = myStack.size();
    myStack.pop();
    bool isempty = myStack.empty(); */

    /* queue<int> myQueue(2);

    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    myQueue.pop(); */

    /* myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    myQueue.push(4);
    myQueue.push(5);
    myQueue.push(6);
    myQueue.push(7);
    myQueue.resize(5);
    myQueue.push(6);
    int frontVal = myQueue.front();
    myQueue.push(2);
    int backVal = myQueue.back();
    int size = myQueue.size();
    myQueue.push(3);
    myQueue.push(4);
    myQueue.pop();
    size = myQueue.size();
    myQueue.pop();
    bool isempty = myQueue.empty(); */

    /* Node<int>* myNode = new Node<int>(5);
    myNode->killSelf(); */

    /* List<int>* myPtr;
    ForwardList<int> myList;
    myPtr = &myList;
    bool isEmpty = myPtr->empty();
    int frontVal = myPtr->front(); */
    /* myPtr->push_back(23);
    myPtr->push_front(2);
    myPtr->push_front(14);
    frontVal = myPtr->front();
    int backVal = myPtr->back();
    isEmpty = myPtr->empty();
    myPtr->pop_front();
    myPtr->pop_back(); */
    /* myPtr->push_back(38);
    myPtr->push_back(14);
    myPtr->push_back(56);
    myPtr->push_back(1);
    myPtr->push_back(54);
    myPtr->push_back(23);
    myPtr->push_back(87);
    myPtr->push_back(39);
    int idxVal = myList[-1];
    idxVal = myList[0];
    idxVal = myList[1];
    idxVal = myList[2];
    idxVal = myList[3];
    myPtr->sort();
    myPtr->clear();
    myPtr->push_back('a');
    isEmpty = myPtr->empty();
    myPtr->reverse(); */

    /* List<int>* myPtr,* myPtr2;
    ForwardList<int> myList, myList2;
    myPtr = &myList;
    myPtr2 = &myList2;
    myPtr->push_front(15);
    myPtr->push_front(10);
    myPtr->push_front(5);

    myPtr2->push_front(20);
    myPtr2->push_front(3);
    myPtr2->push_front(2);
    myList.merge(myList2); */

    /* LinkedList<int> myList, myList2;
    myList.push_front(1);
    myList.push_front(0);
    myList.push_back(2);
    myList.pop_front();
    myList.pop_back();
    myList.push_back(3);
    myList.push_back(4);
    myList.push_back(5);
    myList.push_back(6);
    myList.push_back(7);
    myList.push_back(8);
    myList.push_back(9);
    myList.push_back(10);
    int val;
    for (int i = 0; i < 11; i++){
        val = myList[i];
    }
    myList.clear();
    myList2.push_back(34);
    myList2.push_back(65);
    myList2.push_back(15);
    myList2.push_back(4);
    myList2.push_back(22);
    myList2.push_back(19);
    myList2.push_back(78);
    myList2.sort();
    myList2.reverse();
    myList.merge(myList2); */

    return EXIT_SUCCESS;
}