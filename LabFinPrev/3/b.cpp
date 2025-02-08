#include <iostream>
#include <vector>
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

bool detectCycle(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return true;
        }
    }
    return false;
}

bool isCircular(Node* head) {
    if (!head) return false;
    
    Node* temp = head->next;
    while (temp && temp != head)
        temp = temp->next;

    return (temp == head);
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
    if(detectCycle(ll.head)){
        cout << "Cycle" << endl;
    }
    else cout << "Not Cycle" << endl;
}