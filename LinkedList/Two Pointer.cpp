#include <iostream>
using namespace std;

class Node{
public:
  int val;   
  Node *next;  
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


bool checkTwoPointers(Node* head1, Node* head2){
    Node* ptr1 = head1;
    Node* ptr2 = head2;

    while(ptr1!= NULL && ptr2!= NULL){
        if(ptr1->val != ptr2->val){
            return false;
        }

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return(ptr1==NULL && ptr2==NULL);

}

int main(){
    LinkedList ll1;
    ll1.insertAtTail(4);
    ll1.insertAtTail(5);
    ll1.insertAtTail(6);
    ll1.display();

    LinkedList ll2;
    ll2.insertAtTail(4);
    ll2.insertAtTail(6);
    ll2.insertAtTail(6);
    ll2.display();

    if(checkTwoPointers(ll1.head, ll2.head)){
        cout << "Equal" << endl;
    }
    else{
        cout << "Unequal" << endl;
    }
}