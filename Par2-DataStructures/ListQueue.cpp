#include<iostream>
#include<cassert>
using namespace std;


template<typename T>
class Queue{
    struct Node{
        Node* link;
        T item;
    };
    Node* front;
    Node* back;
    int length{};
public:
    Queue(){
        front = NULL;
        back = NULL;
        length = 0;
    }
    bool isEmpty(){
        return length==0;
    }
    int queueSize(){
        return length;
    }
    void clear(){
        while(front!= nullptr){
            dequeue();
        }
    }
    void enqueue(T element){
        Node* newNode = new Node();
        newNode->item = element;
        newNode->link = NULL;
        if(isEmpty()){
            front = newNode;
            back = newNode;
            length++;
            return;
        }
        back->link = newNode;
        back = newNode;
        length++;
    }
    T dequeue(){
        assert(!isEmpty());
        Node* dequeuedNode = front;
        T element = dequeuedNode->item;
        front = front->link;
        length--;
        if(length == 0){
            back = NULL;
        }
        delete dequeuedNode;
        return element;
    }
    T first(){
        assert(!isEmpty());
        return (front->item);
    }
    void print(){
        Node* curr = front;
        while(curr!=NULL){
            cout<<(curr->item)<<" ";
            curr = curr->link;
        }
        cout<<endl;
    }
};


