#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val[2];
    Node* next;
    Node(int a, int b) {
        val[0] = a;
        val[1] = b;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;
    LinkedList() {
        head = NULL;
        tail = NULL;
    }
    void insert(int a, int b) {
        Node* temp = new Node(a, b); 
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val[0] << " " << temp->val[1] << endl;
            temp = temp->next;
        }
    }
    void sort() {
        Node* temp = head;
        while (temp != NULL) {
            Node* temp1 = temp->next;
            while (temp1 != NULL) {
                if (temp->val[0] > temp1->val[0]) {
                    swap(temp->val[0], temp1->val[0]);
                    swap(temp->val[1], temp1->val[1]);
                } 
                else if (temp->val[0] == temp1->val[0]) {
                    if (temp->val[1] > temp1->val[1]) {
                        swap(temp->val[0], temp1->val[0]);
                        swap(temp->val[1], temp1->val[1]);
                    }
                }
                temp1 = temp1->next;
            }
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList ll;
    int n;
    cin >> n;
    while(n--) {
        int a, b;
        cin >> a >> b;
        ll.insert(a, b);
    }
    ll.sort();
    ll.display();
    
    return 0;
}
