// Problem Statement:
// 1. Create a singly linked list by inserting nodes one by one at the end.
// 2. Display the linked list.
// 3. Insert a new item at a specific position (in the middle).
// 4. Search for an item in the linked list.

#include <iostream>
using namespace std;

// Define a Node
struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display the linked list
void displayList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Function to insert a node at a specific position
void insertAtPosition(Node*& head, int position, int value) {
    Node* newNode = createNode(value);
    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* temp = head;
    for (int i = 1; i < position - 1 && temp; i++) {
        temp = temp->next;
    }
    if (!temp) {
        cout << "Position out of bounds!" << endl;
        delete newNode;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to search for an item in the linked list
bool searchItem(Node* head, int value) {
    Node* temp = head;
    while (temp) {
        if (temp->data == value) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main() {
    Node* head = nullptr;

    // Insert nodes at the end
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);

    // Display the linked list
    cout << "Linked List: ";
    displayList(head);

    // Insert a new item at position 3
    cout << "\nInserting 25 at position 3..." << endl;
    insertAtPosition(head, 3, 25);
    cout << "Updated Linked List: ";
    displayList(head);

    // Search for an item
    int searchValue = 30;
    cout << "\nSearching for " << searchValue << "..." << endl;
    if (searchItem(head, searchValue)) {
        cout << searchValue << " found in the list." << endl;
    } else {
        cout << searchValue << " not found in the list." << endl;
    }

    return 0;
}
