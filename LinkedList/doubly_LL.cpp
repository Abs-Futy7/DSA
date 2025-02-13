#include <iostream>
using namespace std;

// Node class for a doubly linked list
class Node {
public:
    int val;        // Value stored in the node
    Node* prev;     // Pointer to the previous node
    Node* next;     // Pointer to the next node

    // Constructor to initialize a node with given data
    Node(int data) {
        val = data;
        prev = NULL;
        next = NULL;
    }
};

// Doubly_LL class for managing the doubly linked list
class Doubly_LL {
public:
    Node* head;     // Pointer to the head of the list
    Node* tail;     // Pointer to the tail of the list

    // Constructor to initialize an empty doubly linked list
    Doubly_LL() {
        head = NULL;
        tail = NULL;
    }

    // Function to display the elements of the doubly linked list
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val << " ";   // Print the value of the current node
            temp = temp->next;          // Move to the next node
        }
        cout << endl;
    }

    // Function to insert a new node at the head of the list
    void insertAtHead(int val) {
        Node* new_node = new Node(val); // Create a new node with the given value

        if (head == NULL) {             // If the list is empty
            head = new_node;
            tail = new_node;
            return;
        }

        new_node->next = head;          // Link new node to the current head
        head->prev = new_node;          // Link current head's previous to new node
        head = new_node;                // Update head to new node
    }

    // Function to insert a new node at the end of the list
    void insertAtEnd(int val) {
        Node* new_node = new Node(val); // Create a new node with the given value

        if (tail == NULL) {             // If the list is empty
            head = new_node;
            tail = new_node;
            return;
        }

        tail->next = new_node;          // Link current tail to the new node
        new_node->prev = tail;          // Link new node's previous to current tail
        tail = new_node;                // Update tail to new node
    }

    // Function to insert a new node after the k-th node (1-based index)
    void insertAt_Kth(int val, int k) {
        Node* temp = head;
        int count = 1;

        // Move temp to the (k-1)th node
        while (count < (k - 1) && temp != NULL) {
            temp = temp->next;
            count++;
        }

        // If temp is null, k is out of bounds
        if (temp == NULL) {
            cout << "Invalid position\n";
            return;
        }

        // Create a new node with the given value
        Node* new_node = new Node(val);

        // Adjust pointers to insert new node after (k-1)th node
        new_node->next = temp->next;
        temp->next = new_node;
        
        // Handle previous pointer
        if (new_node->next != NULL) {
            new_node->next->prev = new_node;
        }
        new_node->prev = temp;
    }

    // Function to delete the head node of the list
    void deletetAtHead() {
        if (head == NULL) {             // If the list is empty
            return;
        }
        
        Node* temp = head;              // Store current head in temp
        head = head->next;              // Move head to the next node

        if (head == NULL) {             // If head is now null, list becomes empty
            tail = NULL;
        } else {
            head->prev = NULL;          // Otherwise, update new head's previous to null
        }

        free(temp);                    // Free memory allocated to previous head
    }

    void deleteAtEnd(){

        if(head==NULL){
            return;
        }

        Node* temp = tail;
        tail = tail->prev;
        if(tail==NULL){
            head = NULL;
        }
        else{
            tail->next = NULL;
        }

        free(temp);
        return;
    }

    void deleteAtPosition(int k){

        Node* temp = head;
        int count = 1;
        while(count < 1){
            temp = temp->next;
            count++;
        }

        //now temp is positioning at kth position
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
        return;
    }
};

// Main function to test the doubly linked list operations
int main() {
    Doubly_LL dll;                    // Create an empty doubly linked list

    // Insert elements at head and end of the list
    dll.insertAtHead(3);
    dll.insertAtHead(7);
    dll.insertAtHead(5);
    dll.insertAtEnd(6);
    dll.insertAtEnd(4);

    // Display the current state of the list
    dll.display();

    // Delete the head node and display the list again
    dll.deletetAtHead();
    dll.display();

    dll.deleteAtEnd();
    dll.display();

    return 0;
}
