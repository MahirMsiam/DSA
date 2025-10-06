// Problem Statement:
// 1. Check if the stack is full or empty.
// 2. Add three elements to the stack.
// 3. Show the elements of the stack.
// 4. Remove the last two elements from the stack.
// 5. Show the remaining elements.

#include <iostream>
#define MAX 100 // Maximum size of the stack
using namespace std;

class Stack {
private:
    int arr[MAX]; // Array to hold stack elements
    int top;      // Index of the top element

public:
    // Constructor
    Stack() { top = -1; }

    // Check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if the stack is full
    bool isFull() {
        return top == MAX - 1;
    }

    // Push an element onto the stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack overflow! Cannot push " << value << "." << endl;
            return;
        }
        arr[++top] = value;
        cout << value << " pushed onto the stack." << endl;
    }

    // Pop an element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow! Cannot pop an element." << endl;
            return;
        }
        cout << arr[top--] << " popped from the stack." << endl;
    }

    // Display the elements of the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack stack;

    // Check if the stack is empty
    cout << (stack.isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;

    // Add three elements to the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Display the elements of the stack
    stack.display();

    // Remove the last two elements from the stack
    stack.pop();
    stack.pop();

    // Show the remaining elements of the stack
    stack.display();

    // Check if the stack is full
    cout << (stack.isFull() ? "Stack is full." : "Stack is not full.") << endl;

    return 0;
}
