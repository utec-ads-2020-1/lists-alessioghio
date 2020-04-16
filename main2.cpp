#include <iostream>
#include "test/tester.h"
#include "structures/stack.h"
#include "structures/queue.h"

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

    queue<int> myQueue;

    myQueue.push(1);
    int frontVal = myQueue.front();
    myQueue.push(2);
    int backVal = myQueue.back();
    int size = myQueue.size();
    myQueue.pop();
    size = myQueue.size();
    myQueue.pop();
    bool isempty = myQueue.empty();

    return EXIT_SUCCESS;
}
