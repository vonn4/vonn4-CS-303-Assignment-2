// Stack_Vector.cpp
#include "Stack_Vector.h"

// Push an element onto the stack
void Stack::push(int value) {
    stack.push_back(value);
}

// Pop the top element from the stack
void Stack::pop() {
    if (!empty_stack()) {
        cout << "Popped element: " << stack.back() << endl;
        stack.pop_back();
    }
    else {
        cout << "Stack is empty. Cannot pop." << endl;
    }
}

// Get the top element of the stack
int Stack::top_element() const {
    if (!empty_stack()) {
        return stack.back();
    }
    throw out_of_range("Stack is empty.");
}

// Check if the stack is empty
bool Stack::empty_stack() const {
    return stack.empty();
}

// Calculate the average of stack elements
double Stack::average() const {
    if (empty_stack()) return 0.0;

    double sum = 0;
    for (int num : stack) {
        sum += num;
    }
    return sum / stack.size();
}

// Get the size of the stack
size_t Stack::size_stack() const {
    return stack.size();
}

// Get the internal stack (for display purposes)
const vector<int>& Stack::getStack() const {
    return stack;
}
