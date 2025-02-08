#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = prev = NULL;
        }
};

class LinkedList{
    public:
    Node* head;
    Node* tail;
    LinkedList(){
        head = tail = NULL;
    }

    // Insert at head O(1)

    void insertAtHead(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }

        else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Insert at Tail O(1)

    void insertAtTail(int val){
        Node* newNode = new Node(val);
        if(tail == NULL){
            head = tail = newNode;
        }

        else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Delete O(1)

    void deleteNode(Node* node){
        if(node == NULL) return;

        if(node == head){
            head = head->next;
            if(head) head->prev = NULL;
        }
        else if(tail == NULL){
            tail = node->prev;
            if(tail) tail->next = NULL;
        }

        else{
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        delete node;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;
    list.insertAtHead(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.insertAtTail(40);
    list.display();
    
    list.deleteNode(list.head->next); // Deleting middle node (20)
    list.display();

    return 0;
}