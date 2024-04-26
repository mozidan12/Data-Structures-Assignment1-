//
// Created by farah on 22/04/2024.
//

#ifndef DATA_STRUCTURES_ASSIGNMENT1_LINKEDLIST_H
#define DATA_STRUCTURES_ASSIGNMENT1_LINKEDLIST_H
#include <iostream>
using namespace std;
template <typename T>
class Node{
public:
    T data;
    Node<T> *next;
    Node<T> *prev;
    Node(): data(), next(nullptr), prev(nullptr){}
    Node(T value) : data(value), next(NULL), prev(NULL) {}
    friend std::ostream& operator<<(std::ostream& os, const Node<T>* n) {
        os << n->data;
        return os;
    }
};
template <typename T>
class LinkedList {
private:
    Node<T> *first;
public:
    LinkedList<T>(): first{}{}
    LinkedList(T *A, int n) {
        Node<T> *last;
        Node<T> *p;

        first = new Node<T>;
        first->data = A[0];
        first->next= nullptr;
        last = first;

        for(int i = 1; i < n; i++){
            p = new Node<T>;
            p->data = A[i]; //add data to t
            p->next = nullptr; //make t last node
            last->next = p; //insert t by making the previously last node point to it
            last = p;
        }
    }

    ~LinkedList() {
        Node<T> *p=first; //let p point to first node
        while(first){ //until no more nodes or first is null
            first = first->next; //change address of first pointer to the next
            delete p; //delete address of originally first pointer
            p = first; //p is now the next element
        }
    }

    void display() {
        Node<T> *p = first;
        if(first == nullptr) {
            cout << "List is empty\n";
            return;
        }
        while(p){
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    int length() {
        Node<T> *p = first;
        int len = 0;

        while(p){
            len++;
            p = p->next;
        }

        return len;
    }


    void insertAt(int index, T x) {
        Node<T> *t;
        Node <T> *p{first};

        if(index < 0 or index > length()){
            return;
        }

        t = new Node<T>;
        t->data = x;
        t->next = nullptr;

        if(index == 0){
            t->next = first;
            first = t;
        }
        else{
            for(int i = 0; i < index-1; i++){
                p = p->next;
            }
            t->next = p->next;
            p->next = t;
        }
    }


    void insertAtHead(T x) {
        Node<T>*t;
        t = new Node<T>;
        t->data = x;
        t->next = nullptr;
        t->next = first;
        first = t;
    }


    void insertAtTail(T x) {
        Node<T>* newNode = new Node<T>;
        newNode->data = x;
        newNode->next = nullptr;

        if (first == nullptr) {
            // If the list is empty, the new node becomes the first node
            first = newNode;
        }
        else{
            Node<T>* current = first;
            while(current->next != nullptr){
                current = current->next;
            }
            current->next = newNode;
        }
    }


    void removeAt(int index) {
        Node<T> *p;
        Node <T> *q = nullptr;
        if(index < 0 or index > length())
            return;
        if(index == 0){
            p = first;
            first = first->next;
            delete p;
        }
        else{
            p = first;
            for(int i = 0; i < index ; i++){
                q = p;
                p = p->next;
            }
            q->next = p->next;
            delete p;
        }
    }


    void removeAtHead() {
        Node<T>* p{first};
        first = first->next;
        delete p;
    }


    void removeAtTail() {
        if (first == nullptr) {
            return; // List is empty, nothing to remove
        }

        if (first->next == nullptr) {
            // If there's only one node in the list
            delete first;
            first = nullptr;
            return;
        }

        Node<T>* current{first};
        while(current->next->next != nullptr){
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }


    void replaceAt(T x, int index) {
        Node<T> *t;
        Node<T> *p{first};

        if(index < 0 or index > length()){
            return;
        }

        t = new Node<T>;
        t->data = x;
        t->next = nullptr;

        if(index == 0){
            t->next = first->next;
            delete first;
            first = t;
        }
        else{
            for(int i = 0; i < index-1; i++){
                p = p->next;
            }
            t->next = p->next->next;
            delete p->next;
            p->next = t;
        }
    }


    Node<T>* retrieveAt(int index) {
        if(index == 0){
            return first;
        }
        Node<T>* currentNode = first;
        int currentIndex = 0;
        while(currentIndex < index and currentNode!= nullptr){
            currentNode = currentNode->next;
            currentIndex++;
        }
        if(currentIndex==index and currentNode!= nullptr)
            return currentNode;
        else
            return nullptr;

    }


    bool exists(T x) {
        if(first->data == x) return true;
        Node<T>* currentNode{first};
        while(currentNode!= nullptr){
            if(currentNode->data == x)
                return true;
            currentNode = currentNode->next;
        }
        return false;
    }


    bool equals(int index, T x) {
        if(index==0 and first->data == x) return true;
        int currentIndex = 0;
        Node<T>* currentNode{first};
        while(currentIndex < index and currentNode!= nullptr){
            currentNode = currentNode->next;
            currentIndex++;
        }
        if(currentIndex==index and currentNode!= nullptr and currentNode->data == x)
            return true;
        else return false;
    }


    bool isEmpty() {
        if(length() == 0)
            return true;
        return false;
    }


    void clear(){
        while(first != nullptr)
            removeAtHead();
    }


};

#endif //DATA_STRUCTURES_ASSIGNMENT1_LINKEDLIST_H