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

Node* mergedLinkedList(Node* head1, Node* head2){
    Node* dummyhead = new Node(-1);
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    Node* ptr3 = dummyhead;

    while(ptr1 && ptr2){
        if(ptr1->val < ptr2->val){
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }
        else{
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }

    if(ptr1){
        ptr3->next = ptr1;
    }
    else{
        ptr3->next = ptr2;
    }

    return dummyhead->next;
}

Node* mergedKLinkedList(vector<Node*>& lists){
    if(lists.size() == 0) return nullptr;
    while(lists.size() > 1){
        Node* mergedHead = mergedLinkedList(lists[0], lists[1]);
        lists.push_back(mergedHead);
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }
    return lists[0];
}

int main(){
    LinkedList ll1;
    ll1.insertAtTail(4);
    ll1.insertAtTail(5);
    ll1.insertAtTail(6);
    ll1.display();

    LinkedList ll2;
    ll2.insertAtTail(1);
    ll2.insertAtTail(2);
    ll2.insertAtTail(9);
    ll2.display();

    LinkedList ll3;
    ll3.insertAtTail(11);
    ll3.insertAtTail(-3);
    ll3.insertAtTail(34);
    ll3.display();

    vector<Node*> lists;
    lists.push_back(ll1.head);
    lists.push_back(ll2.head);
    lists.push_back(ll3.head);

    LinkedList mergedLL;
    mergedLL.head = mergedKLinkedList(lists);
    mergedLL.display();
}
