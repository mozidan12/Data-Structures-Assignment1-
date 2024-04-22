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

int LinkedList::removeAt(int index) {
    Node *p, *q = nullptr;
    int x = -1;
    if(index < 1 or index > length())
        return -1;
    if(index == 1){
        p = first;
        first = first->next;
        x = p->data;
        delete p;
    }
    else{
        p = first;
        for(int i = 0; i < index - 1; i++){
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
    }
    return x;
}