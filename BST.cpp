// Problem Statement:
// 1. Store student information (ID, Name, CGPA) in a Binary Search Tree (BST).
// 2. Use the unique ID as the key for insertion and searching.
// 3. Implement traversal methods: In-order, Pre-order, and Post-order.

#include <iostream>
#include <string>
using namespace std;

// Define the structure for a BST Node
struct Node {
    int id;
    string name;
    float cgpa;
    Node* left;
    Node* right;

    // Constructor to initialize a node
    Node(int _id, string _name, float _cgpa)
        : id(_id), name(_name), cgpa(_cgpa), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    // Helper function for insertion
    Node* insert(Node* root, int id, string name, float cgpa) {
        if (root == nullptr) {
            return new Node(id, name, cgpa);
        }
        if (id < root->id) {
            root->left = insert(root->left, id, name, cgpa);
        } else if (id > root->id) {
            root->right = insert(root->right, id, name, cgpa);
        } else {
            cout << "Duplicate ID not allowed." << endl;
        }
        return root;
    }

    // Helper function for in-order traversal
    void inOrder(Node* root) {
        if (root != nullptr) {
            inOrder(root->left);
            cout << "ID: " << root->id << ", Name: " << root->name << ", CGPA: " << root->cgpa << endl;
            inOrder(root->right);
        }
    }

    // Helper function for pre-order traversal
    void preOrder(Node* root) {
        if (root != nullptr) {
            cout << "ID: " << root->id << ", Name: " << root->name << ", CGPA: " << root->cgpa << endl;
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    // Helper function for post-order traversal
    void postOrder(Node* root) {
        if (root != nullptr) {
            postOrder(root->left);
            postOrder(root->right);
            cout << "ID: " << root->id << ", Name: " << root->name << ", CGPA: " << root->cgpa << endl;
        }
    }

    // Helper function to search for a node by ID
    Node* search(Node* root, int id) {
        if (root == nullptr || root->id == id) {
            return root;
        }
        if (id < root->id) {
            return search(root->left, id);
        }
        return search(root->right, id);
    }

public:
    // Constructor
    BST() : root(nullptr) {}

    // Insert a node into the BST
    void insert(int id, string name, float cgpa) {
        root = insert(root, id, name, cgpa);
    }

    // Perform in-order traversal
    void inOrder() {
        cout << "In-Order Traversal:" << endl;
        inOrder(root);
    }

    // Perform pre-order traversal
    void preOrder() {
        cout << "Pre-Order Traversal:" << endl;
        preOrder(root);
    }

    // Perform post-order traversal
    void postOrder() {
        cout << "Post-Order Traversal:" << endl;
        postOrder(root);
    }

    // Search for a node by ID
    void search(int id) {
        Node* result = search(root, id);
        if (result) {
            cout << "Found - ID: " << result->id << ", Name: " << result->name << ", CGPA: " << result->cgpa << endl;
        } else {
            cout << "Student with ID " << id << " not found." << endl;
        }
    }
};

int main() {
    BST bst;

    // Insert student records
    bst.insert(101, "Alice", 3.8);
    bst.insert(102, "Bob", 3.5);
    bst.insert(103, "Charlie", 3.9);

    // Perform traversals
    bst.inOrder();
    bst.preOrder();
    bst.postOrder();

    // Search for a student by ID
    cout << endl;
    bst.search(102);
    bst.search(104);

    return 0;
}
