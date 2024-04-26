//
// Created by farah on 25/04/2024.
//

#ifndef UNTITLED1_CIRCULARLIST_H
#define UNTITLED1_CIRCULARLIST_H
#include <iostream>
#include "LinkedList.h"
using namespace std;
template <typename T>
class CircularList{
    Node<T>*head;
public:
    CircularList(): head{}{}
    CircularList(T A[], int n){
        Node<T>*t;
        Node<T>*last;
        head = new Node<T>;
        head->data = A[0];
        head->next = head;
        last = head;
        for(int i = 1; i < n; i++){
            t = new Node<T>;
            t->data = A[i];
            t->next = last->next;
            last->next = t;
            last = t;
        }
    }

    int length(){
        if(head == nullptr) return 0;
        int l{};
        Node<T>* current {head};
        do{
            l++;
            current = current->next;
        }while(current != head);
        return l;
    }
    void display(){
        Node<T>* h{head};
        if(head == nullptr){
            cout << "List is empty\n";
            return;
        }
        do{
            cout << h->data << " ";
            h = h->next;
        }while(h!=head);
        cout << endl;
    }

    void insertAt(int index, T x){
        Node<T> *NodetoInsert{new Node<T>};
        Node<T> *current{head};
        if(index == 0){
            insertAtHead(x);
            return;
        }
        if(index == length()-1){
            insertAtTail(x);
            return;
        }
        if(index < 0) {
            delete NodetoInsert;
            return;
        }
        for(int i = 1; i < index; i++){
            current = current->next;
        }
        NodetoInsert->data = x;
        NodetoInsert->next = current->next;
        current->next = NodetoInsert;
    }
    void insertAtHead(T x){
        Node<T> *NodetoInsert{new Node<T>};
        NodetoInsert->data = x;

        if(head == nullptr){
            head = NodetoInsert;
            head->next = head;
            return;
        }

        Node<T> *current{head};

        while(current->next != head){
            current = current->next;
        }

        current->next = NodetoInsert;
        NodetoInsert->next = head;
        head = NodetoInsert;
    }
    void insertAtTail(T x){
        auto* NodetoInsert = new Node<T>(x);

        if(head == nullptr){
            head = NodetoInsert;
            NodetoInsert->next = head;
            return;
        }

        Node<T>*current = head;

        while (current->next != head) {
            current = current->next;
        }

        current->next = NodetoInsert;
        NodetoInsert->next = head;
    }

    void removeAt(int index){
        if(index == 0){
            removeAtHead();
            return;
        }
        if(index == length()-1){
            removeAtTail();
            return;
        }
        if(index < 0 or index >= length())
            return;

        Node<T>* current{head};
        for(int i = 1; i < index - 2; i++){
            current = current->next;
        }
        Node<T>* toDelete{current->next};
        current->next = toDelete->next;
        delete toDelete;

    }
    void removeAtHead(){
        Node<T>* current{head};
        while(current->next!=head){
            current = current->next;
        }
        if(current == head) {
            delete head;
            head = nullptr;
            return;
        }
        current->next = head->next;
        delete head;
        head = current->next;
    }
    void removeAtTail(){
        if(head == nullptr) return;
        if(head->next == head){
            delete head;
            head = nullptr;
            return;
        }
        Node<T>*current = head;
        Node<T>* previous{};
        while (current->next != head) {
            previous = current;
            current = current->next;
        }

        previous->next = head; //let pointer of second to last node point to head
        delete current; //free memory of last node


    }

    void replaceAt(int index, T x){
        if(index < 0 or index >= length()){
            return;
        }

        Node<T> *replacement = new Node<T>;
        replacement->data = x;
        replacement->next = nullptr;

        if(index == 0){
            if (head == nullptr) {
                // Handle empty list case
                delete replacement;
                return;
            }
            Node<T> *current{head};
            while(current->next!=head){
                current = current->next;
            }
            current->next = replacement;
            replacement->next = head->next;
            delete head;
            head = replacement;
            return;
        }
        else {
            Node<T> *current{head};
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            Node<T> *nodeToReplace = current->next;
            current->next = replacement;
            replacement->next = nodeToReplace->next;
            delete nodeToReplace;
        }

    }
    Node<T>* retrieveAt(int index){
        if(index < 0 or index >= length()) return nullptr;
        if(index == 0)
            return head;
        Node<T>* currentNode = head;
        int currentIndex = 0;
        do{
            currentNode = currentNode->next;
            currentIndex++;
        }while(currentIndex < index and currentNode!= head);
        if(currentIndex==index and currentNode!= nullptr)
            return currentNode;
        else
            return nullptr;
    }

    void swap(int firstIndex, int secondIndex){
        if(firstIndex < 0 || firstIndex>=length() || secondIndex < 0 || secondIndex>= length()) {
            cout << "Index is out of range\n";
            return; }
        if(firstIndex==secondIndex) return;

        Node<T>* a{head};
        Node<T>* prevA{nullptr};
        for(int i = 0; i < firstIndex; i++){
            prevA = a;
            a = a->next;
        }

        Node<T>* b{head};
        Node<T>* prevB{nullptr};
        for(int i = 0; i < secondIndex; i++){
            prevB = b;
            b = b->next;
        }

        if(!a or !b) return;

        if(a->next != head) {//if a is not the tail
            if(prevA){ //if a is not the head
                prevA->next = b;
            }
            else { // a is head but not tail
                head = b;
                // Update the next pointer of the last node to point to the new head
                Node<T>* temp = b;
                while (temp->next != a) {
                    temp = temp->next;
                }
                temp->next = head;
            }
        }
        else { //if a is the tail
            if(prevA) {
                prevA->next = b; } //if a is not the head
            else {
                head = b;
                while (b->next != a) {
                    b = b->next;
                }
                b->next = head;
            } // if a is both the head and the tail
        }
        if (b->next != head) {
            if (prevB)
                prevB->next = a;
            else {
                head = a;
                Node<T>* temp = a;
                while (temp->next != b) {
                    temp = temp->next;
                }
                temp->next = head;
            }
        }
        else {//if b is the tail
            if(prevB) { prevB->next = a; } //if a is not the head
            else {
                head = a;
                while (a->next != b) {
                    a = a->next;
                }
                a->next = head;
            } // if a is both the head and the tail
        }
        //swap next pointers
        Node<T>* temp = b->next;
        b->next = a->next;
        a->next = temp;
    }
    bool exists(T x) {
        if(head == nullptr) return false;
        if(head->data == x) return true;

        Node<T>* currentNode{head};
        do{
            if(currentNode->data == x)
                return true;
            currentNode = currentNode->next;
        }while(currentNode != head);
        return false;
    }
    bool equals(int index, T x){
        if(index==0 and head->data == x) return true;
        int currentIndex = 0;
        Node<T>* currentNode{head};
        do{
            currentNode = currentNode->next;
            currentIndex++;
        }while(currentIndex < index and currentNode!= head);
        if(currentIndex==index and currentNode != head and currentNode->data == x)
            return true;
        else return false;
    }
    bool isEmpty(){
        if(length()) return false;
        else return true;
    }
    void clear(){
        while(head != nullptr)
            removeAtHead();
    }

};
#endif //UNTITLED1_CIRCULARLIST_H
