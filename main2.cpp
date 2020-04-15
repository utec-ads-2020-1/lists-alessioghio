#include <iostream>
#include "test/tester.h"
#include "structures/stack.h"
/* #include "structures/queue.h" */

using namespace std;


int main(int argc, char *argv[]) {
    
    stack<int> myStack;

    myStack.push(1);
    int topVal = myStack.top();
    myStack.push(2);
    int size = myStack.size();
    myStack.pop();
    size = myStack.size();
    myStack.pop();
    bool isempty = myStack.empty();

    return EXIT_SUCCESS;
}
