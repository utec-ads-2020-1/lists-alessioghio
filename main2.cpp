#include <iostream>
#include "test/tester.h"
#include "structures/stack.h"
#include "structures/queue.h"
#include "structures/lists/list.h"
#include "structures/lists/forward.h"
#include "structures/lists/node.h"

using namespace std;


int main(int argc, char *argv[]) {
    
    /* stack<int> myStack;

    myStack.push(1);
    int topVal = myStack.peak();
    myStack.push(2);
    int size = myStack.size();
    myStack.pop();
    size = myStack.size();
    myStack.pop();
    bool isempty = myStack.empty(); */

    /* queue<int> myQueue;

    myQueue.push(1);
    int frontVal = myQueue.front();
    myQueue.push(2);
    int backVal = myQueue.back();
    int size = myQueue.size();
    myQueue.pop();
    size = myQueue.size();
    myQueue.pop();
    bool isempty = myQueue.empty(); */

    /* Node<int>* myNode = new Node<int>(5);
    myNode->killSelf(); */

    List<int>* myPtr;
    ForwardList<int> myList;
    myPtr = &myList;
    bool isEmpty = myPtr->empty();
    int frontVal = myPtr->front();
    myPtr->push_back(1);
    myPtr->push_front(2);
    myPtr->push_front(3);
    frontVal = myPtr->front();
    int backVal = myPtr->back();
    isEmpty = myPtr->empty();
    myPtr->pop_front();
    myPtr->pop_back();
    myPtr->push_front(1);
    myPtr->push_back(3);
    myPtr->push_back(4);
    int idxVal = myList[-1];
    idxVal = myList[0];
    idxVal = myList[1];
    idxVal = myList[2];
    idxVal = myList[3];
    idxVal = myList[4];
    myPtr->clear();
    isEmpty = myPtr->empty();

    return EXIT_SUCCESS;
}
