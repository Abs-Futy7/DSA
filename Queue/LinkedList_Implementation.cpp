#include <iostream>
using namespace std;

// Node class represents each element in the queue.
class Node {
    public:
    int data;    // The value stored in the node 
    Node* next;  // Pointer to the next node in the queue.

    // Constructor for Node class
    Node(int data) {
        this->data = data;   // This should be this->data = data; to correctly assign the parameter to the instance variable.
        next = NULL;   // Initially, the next pointer is NULL, indicating the end of the queue.
    }
};

// Queue class represents the queue itself.
class Queue {
    Node* head;  // Pointer to the front of the queue.
    Node* tail;  // Pointer to the rear of the queue.
    int size;    // Variable to track the size of the queue.

public:
    // Constructor initializes an empty queue.
    Queue() {
        this->head = NULL;  // No elements in the queue, so head is NULL.
        this->tail = NULL;  // No elements in the queue, so tail is NULL.
        this->size = 0;     // The size of the queue is initially 0.
    }

    // Method to add an element to the queue.
    void enqueue(int data) {
        Node* new_node = new Node(data);  // Create a new node with the given data.
        if (head == NULL) {  // If the queue is empty,
            head = tail = new_node;  // Set both head and tail to the new node.
        } else {
            tail->next = new_node;  // Link the new node to the current tail.
            tail = new_node;        // Move the tail to point to the new node.
        }
        size++;  // Increment the size of the queue.
    }

    // Method to remove an element from the front of the queue.
    void deque() {
        if (head == NULL) {  // If the queue is empty, return.
            return;
        } else {
            Node* old_head = head;  // Temporarily store the current head.
            Node* new_head = head->next;  // Move head to the next node.
            head = new_head;  // Update the head pointer.
            if (head == NULL) {  // If the queue becomes empty, set the tail to NULL.
                tail = NULL;
            }
            old_head->next = NULL;  // Unlink the old head from the list.
            free(old_head);  // Free the memory used by the old head node.
            size--;  // Decrement the size of the queue.
        }
    }

    // Method to get the current size of the queue.
    int getSize() {
        return size;
    }

    // Method to check if the queue is empty.
    bool isEmpty() {
        return head == NULL;
    }

    // Method to get the data from the front node of the queue.
    int front() {
        if (head == NULL) {  // If the queue is empty, return -1 (or any other error value).
            return -1;
        }
        return head->data;  // Return the data of the front node.
    }
};


int main() {
    Queue qu;  // Create a new Queue object.
    
    // Enqueue elements to the queue.
    qu.enqueue(10);
    qu.enqueue(80);
    qu.enqueue(108);
    qu.enqueue(180);
    
    qu.deque();  // Dequeue the first element (10).

    // Print and dequeue each element until the queue is empty.
    while (!qu.isEmpty()) {
        cout << qu.front() << " ";  // Print the front element.
        qu.deque();  // Dequeue the front element.
    }
}
