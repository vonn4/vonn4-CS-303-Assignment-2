// Single_Linked_List.h
#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <iostream>
#include <stdexcept>

using namespace std;

// Template class for Single Linked List
template<typename Item_Type>
class Single_Linked_List {
private:
    // Node structure
    struct Node {
        Item_Type data;
        Node* next;
        Node(const Item_Type& item) : data(item), next(nullptr) {}
    };

    Node* head;        // Pointer to the first node
    Node* tail;        // Pointer to the last node
    size_t num_items;  // Number of items in the list

public:
    // Constructor
    Single_Linked_List();

    // Destructor
    ~Single_Linked_List();

    // Member functions
    void push_front(const Item_Type& item);
    void push_back(const Item_Type& item);
    void pop_front();
    void pop_back();
    Item_Type front() const;
    Item_Type back() const;
    bool empty() const;
    void insert(size_t index, const Item_Type& item);
    bool remove(size_t index);
    size_t find(const Item_Type& item) const;
    size_t size() const;

    // Display the list
    void display() const;
};

// Constructor Implementation
template<typename Item_Type>
Single_Linked_List<Item_Type>::Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}

// Destructor Implementation
template<typename Item_Type>
Single_Linked_List<Item_Type>::~Single_Linked_List() {
    while (!empty()) {
        pop_front();
    }
}

// Push an item to the front of the list
template<typename Item_Type>
void Single_Linked_List<Item_Type>::push_front(const Item_Type& item) {
    Node* new_node = new Node(item);
    if (empty()) {
        head = tail = new_node;
    } else {
        new_node->next = head;
        head = new_node;
    }
    num_items++;
}

// Push an item to the back of the list
template<typename Item_Type>
void Single_Linked_List<Item_Type>::push_back(const Item_Type& item) {
    Node* new_node = new Node(item);
    if (empty()) {
        head = tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
    num_items++;
}

// Remove the front item of the list
template<typename Item_Type>
void Single_Linked_List<Item_Type>::pop_front() {
    if (!empty()) {
        Node* old_head = head;
        head = head->next;
        delete old_head;
        num_items--;
        if (head == nullptr) {
            tail = nullptr;
        }
    }
}

// Remove the back item of the list
template<typename Item_Type>
void Single_Linked_List<Item_Type>::pop_back() {
    if (!empty()) {
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* current = head;
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = nullptr;
        }
        num_items--;
    }
}

// Get the front item
template<typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::front() const {
    if (!empty()) {
        return head->data;
    }
    throw out_of_range("List is empty.");
}

// Get the back item
template<typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::back() const {
    if (!empty()) {
        return tail->data;
    }
    throw out_of_range("List is empty.");
}

// Check if the list is empty
template<typename Item_Type>
bool Single_Linked_List<Item_Type>::empty() const {
    return head == nullptr;
}

// Insert an item at a specific index
template<typename Item_Type>
void Single_Linked_List<Item_Type>::insert(size_t index, const Item_Type& item) {
    if (index == 0) {
        push_front(item);
    } else if (index >= num_items) {
        push_back(item);
    } else {
        Node* current = head;
        for (size_t i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        Node* new_node = new Node(item);
        new_node->next = current->next;
        current->next = new_node;
        num_items++;
    }
}

// Remove an item at a specific index
template<typename Item_Type>
bool Single_Linked_List<Item_Type>::remove(size_t index) {
    if (index >= num_items) return false;

    if (index == 0) {
        pop_front();
        return true;
    }

    Node* current = head;
    for (size_t i = 0; i < index - 1; ++i) {
        current = current->next;
    }
    Node* to_remove = current->next;
    current->next = to_remove->next;
    if (to_remove == tail) {
        tail = current;
    }
    delete to_remove;
    num_items--;
    return true;
}

// Find the index of the first occurrence of an item
template<typename Item_Type>
size_t Single_Linked_List<Item_Type>::find(const Item_Type& item) const {
    Node* current = head;
    size_t index = 0;
    while (current != nullptr) {
        if (current->data == item) {
            return index;
        }
        current = current->next;
        index++;
    }
    return num_items; // Not found, return the size of the list
}

// Get the size of the list
template<typename Item_Type>
size_t Single_Linked_List<Item_Type>::size() const {
    return num_items;
}

// Display the list
template<typename Item_Type>
void Single_Linked_List<Item_Type>::display() const {
    cout << "Current List: ";
    if (empty()) {
        cout << "List is empty." << endl;
        return;
    }
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

#endif // SINGLE_LINKED_LIST_H
