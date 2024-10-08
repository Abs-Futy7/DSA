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


Node* reverse_Kth_LL(Node* &head, int k){

    Node* prevptr = NULL;
    Node* curptr = head;

    int counter = 0;

    while(curptr!=NULL && counter<k){  // reversing first k nodes
        Node* nextptr = curptr->next;
        curptr->next = prevptr;
        prevptr = curptr;
        curptr = nextptr;
        counter++;
    }
    // currptr will give us (k+1) th node
    if(curptr!=NULL){
        Node* new_head = reverse_Kth_LL(curptr, k);
        head->next = new_head;
    }

    return prevptr;
}


int main() {
    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(9);
    ll.insertAtTail(10);
    ll.insertAtTail(12);

    cout << "Original List: ";
    ll.display();

    ll.head = reverse_Kth_LL(ll.head, 2);
    cout << "Reversed List: ";
    ll.display();

    return 0;
}