#include <iostream>
#include "./srcs/vector.hpp"
#include "./srcs/stack.hpp"
#include <vector>
#include <stack>

int main() {
    std::cout << "Stack" << std::endl;
    ft::stack< int> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.pop();
    myStack.empty();
    int size = myStack.size();
    for (int i = 0; i < size; i++) {
        std::cout << myStack.top() << std::endl;
        myStack.pop();
    }
    std::cout << "Is empty? " << myStack.empty() << std::endl;
    std::cout << "================================" << std::endl;

    std::cout << "Vector" << std::endl;
    ft::vector< int> myVector;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.pop();
    myStack.empty();
    size = myStack.size();
    for (int i = 0; i < size; i++) {
        std::cout << myStack.top() << std::endl;
        myStack.pop();
    }
    std::cout << "Is empty? " << myStack.empty() << std::endl;
    std::cout << "================================" << std::endl;


    return 0;
}
