// C++ program for merge sort on singly linked list

#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

// Function to split the singly linked list into two halves
Node *split(Node *head) {
    Node *fast = head;
    Node *slow = head;

    // Move fast pointer two steps and slow pointer
    // one step until fast reaches the end
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        if (fast != nullptr) {
            slow = slow->next;
        }
    }

    // Split the list into two halves
    Node *temp = slow->next;
    slow->next = nullptr;
    return temp;
}

// Function to merge two sorted singly linked lists
Node *merge(Node *first, Node *second) {
  
    // If either list is empty, return the other list
    if (first == nullptr) return second;
    if (second == nullptr) return first;

    // Pick the smaller value between first and second nodes
    if (first->data < second->data) {

        // Recursively merge the rest of the lists and
        // link the result to the current node
        first->next = merge(first->next, second);
        return first;
    }
    else {
        // Recursively merge the rest of the lists
        // and link the result to the current node
        second->next = merge(first, second->next);
        return second;
    }
}

// Function to perform merge sort on a singly linked list
Node *MergeSort(Node *head) {
  
    // Base case: if the list is empty or has only one node, 
    // it's already sorted
    if (head == nullptr || head->next == nullptr)
        return head;

    // Split the list into two halves
    Node *second = split(head);

    // Recursively sort each half
    head = MergeSort(head);
    second = MergeSort(second);

    // Merge the two sorted halves
    return merge(head, second);
}

void printList(Node *head) {
    Node *curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
      
    // Create a hard-coded singly linked list:
    // 9 -> 8 -> 5 -> 2
    Node *head = new Node(9);
    head->next = new Node(8);
    head->next->next = new Node(5);
    head->next->next->next = new Node(2);

    head = MergeSort(head);
    printList(head);

    return 0;
}