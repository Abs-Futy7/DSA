// C++ program to implement the circular queue using array
#include <bits/stdc++.h>

// defining the max size of the queue
#define MAX_SIZE 5

using namespace std;

// class that represents queue
class Queue {
public:
    // index pointers and data array
    int front, rear;
    int arr[MAX_SIZE];

    // constructor to initialize the index pointers
    Queue() { front = rear = 0; }

    // checking if queue is empty
    bool isEmpty()
    {
        if (front == rear)
            return true;
        return false;
    }

    // checking if the queue is full
    bool isFull()
    {
        if ((rear + 1) % MAX_SIZE == front)
            return true;
        return false;
    }

    // enqueue operation
    void enqueue(int val)
    {
        if (this->isFull()) {
            printf("Queue Overflow!\n");
            return;
        }
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = val;
    }

    // dequeue operation
    void dequeue()
    {
        if (this->isEmpty()) {
            printf("Queue Underflow!\n");
            return;
        }
        front = (front + 1) % MAX_SIZE;
    }

    // peek function
    int peek()
    {
        if (this->isEmpty()) {
            printf("Queue is Empty!\n");
            return -1;
        }
        return arr[(front + 1) % MAX_SIZE];
    }

    // utility to print queue
    void print()
    {
        if (this->isEmpty())
            return;
        for (int i = (front + 1) % MAX_SIZE; i < rear;
             i = (i + 1) % MAX_SIZE) {

            printf("%d ", arr[i]);
        }
        cout << arr[rear];
    }
};

// driver code
int main()
{
    Queue q;

    q.enqueue(11);
    q.enqueue(11);
    q.enqueue(11);
    q.enqueue(11);
    q.enqueue(11);
    q.enqueue(11);

    q.dequeue();

    q.dequeue();
    q.enqueue(123);

    q.print();

    return 0;
}
