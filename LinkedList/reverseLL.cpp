#include <iostream>
using namespace std;

class Node {
    public:
    int val;
    Node* next;

    Node(int data) {
        val = data;
        next = NULL;
    }
};

class LinkedList {
    public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void insertAtTail(int val) {
        Node* new_node = new Node(val);

        if (head == NULL) {
            head = new_node;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = new_node;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

// Function to reverse the linked list
Node* reverseLL(Node* &head) {
    Node* prev_ptr = NULL;
    Node* curr_ptr = head;
    Node* next_ptr = NULL;

    while (curr_ptr != NULL) {
        next_ptr = curr_ptr->next;  // Save the next node
        curr_ptr->next = prev_ptr;  // Reverse the current node's pointer
        prev_ptr = curr_ptr;        // Move prev_ptr to the current node
        curr_ptr = next_ptr;        // Move to the next node in the original list
    }

    head = prev_ptr;  // Update the head to the last node (new head)
    return head;
}

Node* reverseLLRecursion(Node* &head){
    // Base case: if the list is empty or has only one node, return the current node (head)
    if(head == NULL || head->next == NULL){
        return head;
    }

    // Recursive case: reverse the rest of the list starting from the second node
    Node* new_head = reverseLLRecursion(head->next);

    // After the rest of the list is reversed, set the next node's next pointer to point to the current head
    head->next->next = head;

    // Set the current node's next pointer to NULL (since it will now be the last node in the reversed list)
    head->next = NULL;

    // Return the new head of the reversed list, which is the result of reversing the rest of the list
    return new_head;
}



int main() {
    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(5);
    ll.insertAtTail(9);
    ll.insertAtTail(8);

    cout << "Original List: ";
    ll.display(); // Display original list

    ll.head = reverseLL(ll.head); // Reverse the linked list

    cout << "Reversed List: ";
    ll.display(); // Display reversed list

    ll.head = reverseLLRecursion(ll.head);
    cout << "Recursive Reversed List: ";
    ll.display();

    return 0;
}

