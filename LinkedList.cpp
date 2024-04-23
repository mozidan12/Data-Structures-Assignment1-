//
// Created by farah on 22/04/2024.
//
#include <iostream>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList(int *A, int n) {
    Node *last, *t;

    first = new Node;
    first->data = A[0];
    first->next= nullptr;
    last = first;

    for(int i = 1; i < n; i++){
        t = new Node;
        t->data = A[i]; //add data to t
        t->next = nullptr; //make t last node
        last->next = t; //insert t by making the previously last node point to it
        last = t;
    }
}
LinkedList::~LinkedList() {
    Node *p=first; //let p point to first node
    while(first){ //until no more nodes or first is null
        first = first->next; //change address of first pointer to the next
        delete p; //delete address of originally first pointer
        p = first; //p is now the next element
    }
}

void LinkedList::display() {
    Node *p = first;
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

int LinkedList::length() {
    Node *p = first;
    int len = 0;

    while(p){
        len++;
        p = p->next;
    }

    return len;
}

void LinkedList::insertAt(int index, int x) {
    Node *t, *p{first};

    if(index < 0 or index > length()){
        return;
    }

    t = new Node;
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
void LinkedList::insertAtHead(int x) {
    Node *t;
    t = new Node;
    t->data = x;
    t->next = nullptr;
    t->next = first;
    first = t;
}
void LinkedList::insertAtTail(int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = nullptr;

    if (first == nullptr) {
        // If the list is empty, the new node becomes the first node
        first = newNode;
    }
    else{
        Node* current{first};
        while(current->next != nullptr){
            current = current->next;
        }
        current->next = newNode;
    }



}
void LinkedList::removeAt(int index) {
    Node *p, *q = nullptr;
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

void LinkedList::removeAtHead() {
    Node* p{first};
    first = first->next;
    delete p;
}
void LinkedList::removeAtTail() {
    if (first == nullptr) {
        return; // List is empty, nothing to remove
    }

    if (first->next == nullptr) {
        // If there's only one node in the list
        delete first;
        first = nullptr;
        return;
    }

    Node* current{first};
    while(current->next->next != nullptr){
        current = current->next;
    }
    delete current->next;
    current->next = nullptr;
}
void LinkedList::replaceAt(int x, int index) {
    Node *t, *p{first};

    if(index < 0 or index > length()){
        return;
    }

    t = new Node;
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

Node* LinkedList::retrieveAt(int index) {
    if(index == 0){
        return first;
    }
    Node* currentNode = first;
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

bool LinkedList::exists(int x) {
    if(first->data == x) return true;
    Node* currentNode{first};
    while(currentNode!= nullptr){
        if(currentNode->data == x)
            return true;
        currentNode = currentNode->next;
    }
    return false;
}

bool LinkedList::equals(int index, int x) {
    if(index==0 and first->data == x) return true;
    int currentIndex = 0;
    Node* currentNode{first};
    while(currentIndex < index and currentNode!= nullptr){
        currentNode = currentNode->next;
        currentIndex++;
    }
    if(currentIndex==index and currentNode!= nullptr and currentNode->data == x)
        return true;
    else return false;
}

bool LinkedList::isEmpty() {
    if(length() == 0)
        return true;
    return false;
}

void LinkedList::clear(){
    while(first!= nullptr)
        removeAtHead();
}