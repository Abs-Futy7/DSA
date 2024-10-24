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

Node* rotateLLByK(Node* &head, int k) {
    if (!head || k == 0) return head;

    int n = 1; // Initialize n to 1 to count the head node
    Node* tail = head;

    while (tail->next) {
        n++;
        tail = tail->next;
    }

    // Connect the tail to the head to make it circular
    tail->next = head;

    // Find the new tail: (n-k)th node
    k = k % n; // Normalize k
    if (k == 0) {
        tail->next = NULL; // Break the circular link
        return head;
    }

    Node* temp = head;
    for (int i = 1; i < n - k; i++) {
        temp = temp->next;
    }

    // Set new head and break the link
    Node* newHead = temp->next;
    temp->next = NULL;

    return newHead;
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
    ll.head = rotateLLByK(ll.head, 3);
    ll.display();
}