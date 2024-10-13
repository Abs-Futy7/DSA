#include <iostream>
using namespace std;

// Define a Node class for the circular linked list
class Node {
public:
    int val;        // Value stored in the node
    Node* next;     // Pointer to the next node in the list

    // Constructor to initialize a node with a given value
    Node(int data) {
        val = data;
        next = NULL; // Initialize next pointer to NULL
    }
};

// Define a CircularLinkedList class
class CircularLinkedList {
public:
    Node* head;     // Pointer to the head of the circular linked list

    // Constructor to initialize an empty circular linked list
    CircularLinkedList() {
        head = NULL; // Initialize head pointer to NULL (empty list)
    }

    // Method to display the elements of the circular linked list
    void display() {
        Node* temp = head; // Start from the head of the list

        // Traverse the circular linked list
        do {
            cout << temp->val << "->"; // Output the value of the current node
            temp = temp->next;         // Move to the next node
        } while (temp != head);        // Continue until we reach the head again
        cout << endl;
    }

    // Method to insert a new node at the beginning of the circular linked list
    void insertAtStart(int val) {
        Node* new_node = new Node(val); // Create a new node with the given value

        if (head == NULL) { // If the list is empty
            head = new_node;        // Set the new node as the head
            new_node->next = head;  // Make it point to itself (circular)
            return;
        }

        // Find the last node in the current circular linked list
        Node* tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }

        // Now 'tail' points to the last node

        tail->next = new_node;  // Make the last node point to the new node
        new_node->next = head;  // Make the new node point to the head
        head = new_node;        // Update the head to point to the new node
    }

    void insertAtEnd(int val){
        Node* new_node = new Node(val);

        if (head == NULL) { // If the list is empty
            head = new_node;        // Set the new node as the head
            new_node->next = head;  // Make it point to itself (circular)
            return;
        }

        Node* tail = head;
        while(tail->next!=head){
            tail = tail->next;
        }
        tail->next = new_node;
        new_node->next = head;
    }

    void deleteAtStart(){
        if(head == NULL){
            return;
        }

        Node* temp = head;
        Node* tail = head;

        while(tail->next!= head){
            tail = tail->next;
        }

        head = head->next;
        tail->next = head;
        free(temp);
    }

    void deleteAtEnd(){
        if(head==NULL){
            return;
        }

        Node* tail = head;
        while(tail->next->next != head){
            tail = tail->next;
        }

        Node* temp = tail->next; // delete this
        tail->next = head;
        free(temp);
    }
};





int main(){
    CircularLinkedList cll;
    cll.insertAtStart(3);
    cll.insertAtStart(6);
    cll.insertAtStart(4);
    cll.insertAtStart(88);


    cll.display();

    cll.insertAtEnd(6);
    cll.display();

    cll.deleteAtStart();
    cll.display();

    cll.deleteAtEnd();
    cll.display();
}