#include <iostream>
using namespace std;

template <typename T>
class Node{
    public:  
    T val;
    Node* next;

    Node(T data){
        val = data;
        next = NULL;
    }
};

int main(){
    Node<int>* node = new Node<int> (4);
    cout << node->val << endl;

    Node<char>* node2 = new Node<char> ('y');
    cout << node2->val << endl;
}