#include <iostream>
using namespace std;

// Node class to represent each element of the linked list
class Node {
public:
    int data;   // Data part of the node
    Node* next; // Pointer to the next node

    // Constructor to initialize a node
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// LinkedList class to manage the linked list
class LinkedList {
private:
    Node* head; // Head (starting point) of the linked list

public:
    // Constructor to initialize an empty linked list
    LinkedList() {
        head = nullptr;
    }

    // Method to insert a new node at the beginning of the linked list
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data); // Create a new node
        newNode->next = head;          // Point the new node's next to the current head
        head = newNode;                // Update the head to the new node
    }

    // Method to display the linked list elements
    void display() {
        Node* current = head; // Start from the head
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "null" << endl;
    }
};

// Main function to demonstrate the program
int main() {
    LinkedList list;

    // Insert elements at the beginning
    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtBeginning(30);
    list.insertAtBeginning(40);

    // Display the linked list
    cout << "Linked list after inserting elements at the beginning:" << endl;
    list.display();

    return 0;
}
