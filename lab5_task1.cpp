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

    // Method to add a new element to the linked list
    void add(int data) {
        Node* newNode = new Node(data); // Create a new node
        if (head == nullptr) {         // If the list is empty
            head = newNode;            // Make the new node the head
        } else {                       // Otherwise, find the last node and append the new node
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Method to count the number of elements in the linked list
    int countElements() {
        int count = 0;
        Node* current = head; // Start from the head
        while (current != nullptr) { // Traverse until the end
            count++;
            current = current->next; // Move to the next node
        }
        return count; // Return the count
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

    // Add elements to the linked list
    list.add(10);
    list.add(20);
    list.add(30);
    list.add(40);

    // Display the linked list
    cout << "Linked list:" << endl;
    list.display();

    // Find and display the number of elements
    int numOfElements = list.countElements();
    cout << "Number of elements in the linked list: " << numOfElements << endl;

    return 0;
}
