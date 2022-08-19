#include <iostream>
#include "./srcs/vector.hpp"
#include "./srcs/stack.hpp"
#include <vector>
#include <stack>

void printContainer(std::string containerType, std::vector<int> &myVector);

int main() {
//    std::cout << "Stack" << std::endl;
//    ft::stack< int> myStack;
//    myStack.push(1);
//    myStack.push(2);
//    myStack.push(3);
//    myStack.push(4);
//    myStack.pop();
//    myStack.empty();
//    int size = myStack.size();
//    for (int i = 0; i < size; i++) {
//        std::cout << myStack.top() << std::endl;
//        myStack.pop();
//    }
//    std::cout << "Is empty? " << myStack.empty() << std::endl;
//    std::cout << "================================" << std::endl;
//
//    std::cout << "Vector" << std::endl;
//    std::vector<int> myVector;
//    myStack.push(1);
//    myStack.push(2);
//    myStack.push(3);
//    myStack.push(4);
//    myStack.pop();
//    myStack.empty();
//    size = myStack.size();
//    for (int i = 0; i < size; i++) {
//        std::cout << myStack.top() << std::endl;
//        myStack.pop();
//    }
//    std::cout << "Is empty? " << myStack.empty() << std::endl;
//    std::cout << "================================" << std::endl;

    /**** Check ****/
    std::string containerType = "Vector";
    std::vector<int> myVector;

    printContainer(containerType, myVector);
    for (int i = 0; i < 10; i++) {
        myVector.push_back(i);
    }
//    myVector.resize(300);
    myVector.reserve(40);
    myVector.push_back(50);
    for (int i = 0; i < 50; ++i) {
        myVector.pop_back();
    }
    printContainer(containerType, myVector);
//
    return 0;
}

void printContainer(std::string containerType, std::vector<int> &myVector) {
    std::cout << containerType << " max_size: " << myVector.max_size() << std::endl;
    std::cout << containerType << " size: " << myVector.size() << std::endl;
    std::cout << containerType << " capacity: " << myVector.capacity() << std::endl;
//    for (int i = 0; i < myVector.size(); ++i) {
//        std::cout << myVector[i] << " ";
//    }
//    std::cout << std::endl;

}
