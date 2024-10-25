#include <iostream>
#include <vector>  // Don't forget to include vector.
using namespace std;

class Queue {
    int front;   // Points to the front of the queue
    int back;    // Points to the last element in the queue
    vector<int> v;  // Vector to store queue elements

public:
    // Constructor initializes the queue as empty.
    Queue() {
        this->back = -1;
        this->front = -1;
    }

    // Method to add an element to the queue.
    void enqueue(int data) {
        if (this->front == -1) {
            this->front = 0;  // Initialize front to 0 if it's the first element.
        }
        v.push_back(data);    // Add data to the vector.
        this->back++;         // Increment the back pointer.
    }

    // Method to remove an element from the queue.
    void dequeue() {
        if (this->front == -1 || this->front > this->back) {
            // If the queue is empty or the front has passed the back, reset the queue.
            this->front = -1;
            this->back = -1;
        } else {
            this->front++;  // Move the front pointer to the next element.
        }
    }

    // Method to get the front element of the queue.
    int getfront() {
        if (this->front == -1 || this->front > this->back) {
            return -1;  // Return -1 if the queue is empty.
        }
        return this->v[this->front];  // Return the front element.
    }

    // Method to check if the queue is empty.
    bool isEmpty() {
        return this->front == -1 || this->front > this->back;
    }
};

int main() {
    Queue qu;  // Create a new Queue object.
    
    // Enqueue elements to the queue.
    qu.enqueue(10);
    qu.enqueue(80);
    qu.enqueue(108);
    qu.enqueue(180);
    
    qu.dequeue();  // Dequeue the first element (10).

    // Print and dequeue each element until the queue is empty.
    while (!qu.isEmpty()) {
        cout << qu.getfront() << " ";  // Print the front element.
        qu.dequeue();  // Dequeue the front element.
    }
}
