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


void removeFromKthEnd(Node* &head, int k){
    Node* ptr1 = head;
    Node* ptr2 = head;

    //move ptr2 kth steps
    int cnt = k;
    while(cnt--){
        ptr2 = ptr2->next;
    }

    if(ptr2 == NULL){ // k is equal to length of ll
        // we have to delete head node
        Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }
    // now ptr2 is k steps ahead of ptr1

    //when ptr2 is null, ptr1 will be at node to be deleted

    while(ptr2->next != NULL){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    // now ptr1 is pointing to node before kth node from end
    // node to be deleted is ptr1->next

    Node* temp = ptr1->next;
    ptr1->next = ptr1->next->next;
    free(temp);
}

int main(){
    LinkedList ll1;
    ll1.insertAtTail(4);
    ll1.insertAtTail(5);
    ll1.insertAtTail(6);
    ll1.insertAtTail(4);
    ll1.insertAtTail(5);
    ll1.insertAtTail(6);
    ll1.display();

    removeFromKthEnd(ll1.head, 3);
    ll1.display();

}