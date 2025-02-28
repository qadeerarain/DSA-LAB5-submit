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

    // Method to add a node to the sorted linked list
    void add(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr || head->data >= data) {
            // Insert at the beginning if the list is empty or head's data is greater
            newNode->next = head;
            head = newNode;
        } else {
            // Traverse and find the correct position to insert
            Node* current = head;
            while (current->next != nullptr && current->next->data < data) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Method to find the location of the last node
    int findLastNodeLocation() {
        if (head == nullptr) {
            return -1; // List is empty
        }

        int location = 0;
        Node* current = head;

        while (current->next != nullptr) {
            current = current->next;
            location++;
        }

        return location; // Return the index of the last node
    }

    // Method to display the linked list elements
    void display() {
        Node* current = head;
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

    // Add elements to the sorted linked list
    list.add(10);
    list.add(20);
    list.add(30);
    list.add(40);

    // Display the linked list
    cout << "Sorted linked list:" << endl;
    list.display();

    // Find the location of the last node
    int lastNodeLocation = list.findLastNodeLocation();
    if (lastNodeLocation != -1) {
        cout << "Location of the last node: " << lastNodeLocation << endl;
    } else {
        cout << "The linked list is empty." << endl;
    }

    return 0;
}
