// main.cpp
#include <iostream>
#include "Single_Linked_List.h"
#include "Stack_Vector.h"

using namespace std;

// Function to display the Stack
void displayStack(Stack& stackObj) {
    cout << "Current Stack: ";
    if (stackObj.empty_stack()) {
        cout << "Stack is empty." << endl;
        return;
    }
    // Access the internal stack vector
    const vector<int>& internalStack = stackObj.getStack();
    for (auto it = internalStack.rbegin(); it != internalStack.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    Single_Linked_List<int> list;
    Stack stack;
    int choice;

    while (true) {
        cout << "\n==== C++ Data Structures Menu ====" << endl;
        cout << "1. Singly Linked List Operations" << endl;
        cout << "2. Stack Operations" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            // Singly Linked List Menu
            int listChoice;
            while (true) {
                cout << "\n--- Singly Linked List Operations ---" << endl;
                cout << "1. Insert at Front" << endl;
                cout << "2. Insert at Back" << endl;
                cout << "3. Insert at Index" << endl;
                cout << "4. Remove at Index" << endl;
                cout << "5. Find Element" << endl;
                cout << "6. Get Front Element" << endl;
                cout << "7. Get Back Element" << endl;
                cout << "8. Check if List is Empty" << endl;
                cout << "9. Get Size of List" << endl;
                cout << "10. Display List" << endl;
                cout << "11. Return to Main Menu" << endl;
                cout << "Enter your choice: ";
                cin >> listChoice;

                if (listChoice == 1) {
                    int value;
                    cout << "Enter value to insert at front: ";
                    cin >> value;
                    list.push_front(value);
                    cout << "Inserted " << value << " at the front." << endl;
                }
                else if (listChoice == 2) {
                    int value;
                    cout << "Enter value to insert at back: ";
                    cin >> value;
                    list.push_back(value);
                    cout << "Inserted " << value << " at the back." << endl;
                }
                else if (listChoice == 3) {
                    int value, index;
                    cout << "Enter index to insert at: ";
                    cin >> index;
                    cout << "Enter value to insert: ";
                    cin >> value;
                    list.insert(index, value);
                    cout << "Inserted " << value << " at index " << index << "." << endl;
                }
                else if (listChoice == 4) {
                    int index;
                    cout << "Enter index to remove: ";
                    cin >> index;
                    if (list.remove(index)) {
                        cout << "Removed element at index " << index << "." << endl;
                    }
                    else {
                        cout << "Failed to remove. Index " << index << " is out of bounds." << endl;
                    }
                }
                else if (listChoice == 5) {
                    int value;
                    cout << "Enter value to find: ";
                    cin >> value;
                    size_t foundIndex = list.find(value);
                    if (foundIndex != list.size()) {
                        cout << "Element " << value << " found at index " << foundIndex << "." << endl;
                    }
                    else {
                        cout << "Element " << value << " not found in the list." << endl;
                    }
                }
                else if (listChoice == 6) {
                    try {
                        int front = list.front();
                        cout << "Front element: " << front << endl;
                    }
                    catch (const out_of_range& e) {
                        cout << e.what() << endl;
                    }
                }
                else if (listChoice == 7) {
                    try {
                        int back = list.back();
                        cout << "Back element: " << back << endl;
                    }
                    catch (const out_of_range& e) {
                        cout << e.what() << endl;
                    }
                }
                else if (listChoice == 8) {
                    cout << "List is " << (list.empty() ? "empty." : "not empty.") << endl;
                }
                else if (listChoice == 9) {
                    cout << "Size of the list: " << list.size() << endl;
                }
                else if (listChoice == 10) {
                    cout << "Displaying list:" << endl;
                    list.display(); // Use the display method
                }
                else if (listChoice == 11) {
                    break;
                }
                else {
                    cout << "Invalid choice. Please try again." << endl;
                }
            }
        }
        else if (choice == 2) {
            // Stack Menu
            int stackChoice;
            while (true) {
                cout << "\n--- Stack Operations ---" << endl;
                cout << "1. Push Element" << endl;
                cout << "2. Pop Element" << endl;
                cout << "3. Get Top Element" << endl;
                cout << "4. Check if Stack is Empty" << endl;
                cout << "5. Get Size of Stack" << endl;
                cout << "6. Get Average of Stack Elements" << endl;
                cout << "7. Display Stack" << endl;
                cout << "8. Return to Main Menu" << endl;
                cout << "Enter your choice: ";
                cin >> stackChoice;

                if (stackChoice == 1) {
                    int value;
                    cout << "Enter value to push onto the stack: ";
                    cin >> value;
                    stack.push(value);
                    cout << "Pushed " << value << " onto the stack." << endl;
                }
                else if (stackChoice == 2) {
                    stack.pop();
                }
                else if (stackChoice == 3) {
                    try {
                        int top = stack.top_element();
                        cout << "Top element: " << top << endl;
                    }
                    catch (const out_of_range& e) {
                        cout << e.what() << endl;
                    }
                }
                else if (stackChoice == 4) {
                    cout << "Stack is " << (stack.empty_stack() ? "empty." : "not empty.") << endl;
                }
                else if (stackChoice == 5) {
                    cout << "Size of the stack: " << stack.size_stack() << endl;
                }
                else if (stackChoice == 6) {
                    cout << "Average of stack elements: " << stack.average() << endl;
                }
                else if (stackChoice == 7) {
                    cout << "Displaying stack:" << endl;
                    displayStack(stack);
                }
                else if (stackChoice == 8) {
                    break;
                }
                else {
                    cout << "Invalid choice. Please try again." << endl;
                }
            }
        }
        else if (choice == 3) {
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
