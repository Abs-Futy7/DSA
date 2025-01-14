#include <iostream>
using namespace std;


int heap[1000];
int last_index = -1;

int get_max(){
    if(last_index == -1){
        return -1;
    }
    return heap[0];
}

int parent(int i){
    return (i-1)/2;
}


void heapifyUp(int i){
    while(1){
        if (i==0)
            break;
        if(heap[parent(i)]>heap[i])
            break;
        
        // swap
        int temp = heap[parent(i)];
        heap[parent(i)] = heap[i];
        heap[i] = temp;

        i = parent(i);

    }
}

void insert(int x){

    heap[last_index+1] = x;
    last_index++;
    heapifyUp(last_index);

}

int leftChild(int i){
    return 2 * i + 1;
}

int rightChild(int i){
    return 2 * i + 2;
}


void heapifyDown(int i){

    if(leftChild(i) > last_index){
        return;
    }

    int mx_node = -1;
    if(leftChild(i)<=last_index && rightChild(i)>last_index){
        mx_node = leftChild(i);
    }
    else if (heap[leftChild(i)]>heap[rightChild(i)]){
        mx_node = leftChild(i);
    }
    else{
        mx_node = rightChild(i);
    }

    if(heap[i]>=heap[mx_node]){
        return;
    }

    // swap
    int temp = heap[i];
    heap[i] = heap[mx_node];
    heap[mx_node] = temp;

    heapifyDown(mx_node);


}
int extractMax(){
    int ret = heap[0];

    heap[0] = heap[last_index];
    last_index--;


    return ret;
}

int main() {

    insert(10);
    

    return 0;
}