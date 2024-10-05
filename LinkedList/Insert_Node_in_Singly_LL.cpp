#include <iostream>
using namespace std;

// Define a Node class for the linked list
class Node {
public:
  int val;      // Data stored in the node
  Node *next;   // Pointer to the next node in the list

  // Constructor to initialize a node with given data
  Node(int data) {
    val = data; // Initialize node value with data
    next = NULL; // Initialize next pointer to NULL (no next node initially)
  }
};

// Function to insert a new node at the head of the linked list
void insertAtHeadNode(Node *&head, int val) {
  // Create a new node with the given value
  Node *new_node = new Node(val);
  
  // Set the new node's next pointer to the current head of the list
  new_node->next = head;
  
  // Update the head to point to the new node, making it the new head
  head = new_node;
}


void insertAtTail(Node* &head, int val){
    Node* new_node = new Node(val);

    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }

    temp->next = new_node;
}



void insertAtPosition(Node* &head, int val, int pos) {

    // If the position is 0, insert the new node at the head of the list
    if(pos == 0) {
        insertAtHeadNode(head, val); // Use the existing function to insert at the head
        return; // Return early since the insertion is done
    }

    // Create a new node with the given value
    Node* new_node = new Node(val);

    // Temporary pointer to traverse the list and find the insertion point
    Node* temp = head;

    // Variable to keep track of the current position in the list
    int current_pos = 0;

    // Traverse the list until reaching the node just before the desired position
    while(current_pos != pos - 1) {
        temp = temp->next; // Move to the next node
        current_pos++;     // Increment the position counter
    }
    // At this point, 'temp' is pointing to the node at position (pos - 1)

    // Set the new node's 'next' pointer to the node currently at 'pos'
    new_node->next = temp->next;

    // Update the 'next' pointer of the node at 'pos - 1' to point to the new node
    temp->next = new_node;
}



// Function to display the linked list starting from the given head
void display(Node *head) {
  // Temporary pointer to traverse the list, starting from the head
  Node *temp = head;
  
  // Traverse the list until the end (NULL pointer)
  while (temp != NULL) {
    // Print the value of the current node followed by "->"
    cout << temp->val << "->";
    
    // Move to the next node in the list
    temp = temp->next;
  }
  
  // Print "NULL" to indicate the end of the list
  cout << "NULL" << endl;
}

// Main function where execution starts
int main() {
  Node* head = NULL; // Initialize an empty linked list (head is NULL initially)
  
  // Insert a node with value 2 at the head of the list
  insertAtHeadNode(head, 2);
  display(head);
  
  // Insert a node with value 1 at the head of the list
  insertAtHeadNode(head, 1);
  display(head);

    insertAtTail(head, 3);
    display(head);

    insertAtPosition(head, 4, 1);
    display(head);
}
