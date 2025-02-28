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

    // Method to insert a new node at a given position
    void insertAtPosition(int data, int position) {
        Node* newNode = new Node(data); // Create a new node

        // If inserting at the head position (position 0)
        if (position == 0) {
            newNode->next = head; // Set the new node's next to current head
            head = newNode;       // Update head to the new node
            return;
        }

        // Traverse to the node just before the desired position
        Node* current = head;
        int currentIndex = 0;
        while (current != nullptr && currentIndex < position - 1) {
            current = current->next;
            currentIndex++;
        }

        // If the position is invalid (greater than the list size)
        if (current == nullptr) {
            cout << "Position out of bounds!" << endl;
            return;
        }

        // Insert the new node at the given position
        newNode->next = current->next; // Link the new node to the next node
        current->next = newNode;       // Link the previous node to the new node
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

    // Add initial elements to the linked list
    list.insertAtPosition(10, 0); // Insert at position 0
    list.insertAtPosition(20, 1); // Insert at position 1
    list.insertAtPosition(30, 2); // Insert at position 2
    list.insertAtPosition(40, 1); // Insert at position 1

    // Display the linked list
    cout << "Linked list after insertions:" << endl;
    list.display();

    // Attempt to insert at an invalid position
    list.insertAtPosition(50, 10); // Invalid position

    return 0;
}
