// Stack_Vector.h
#ifndef STACK_VECTOR_H
#define STACK_VECTOR_H

#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

// Stack class using a vector
class Stack {
private:
    vector<int> stack; // Vector to store stack elements

public:
    // Member functions
    void push(int value);         // Push an element onto the stack
    void pop();                   // Pop the top element from the stack
    int top_element() const;      // Get the top element
    bool empty_stack() const;     // Check if the stack is empty
    double average() const;       // Calculate the average of stack elements
    size_t size_stack() const;    // Get the size of the stack

    // Additional method to get the internal stack for display purposes
    const vector<int>& getStack() const;
};

#endif // STACK_VECTOR_H
