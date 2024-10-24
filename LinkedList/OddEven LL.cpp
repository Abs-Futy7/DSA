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

Node* oddEvenLL(Node* &head){
    Node* evenHead = head->next;
    Node* oddPtr = head;
    Node* evenPtr = evenHead;

    while(evenPtr && evenPtr->next){
        oddPtr->next = oddPtr->next->next;
        evenPtr->next = evenPtr->next->next;
        oddPtr = oddPtr->next;
        evenPtr = evenPtr->next;
    }

    oddPtr->next = evenHead;
    return head;
}


int main(){
    LinkedList ll;
    int n;
    cin >> n; 
    while(n--){
        int x;
        cin >> x;  
        ll.insertAtTail(x); 
    }
    ll.display(); 
    ll.head = oddEvenLL(ll.head);
    ll.display();
}