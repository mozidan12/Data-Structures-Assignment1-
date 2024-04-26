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

    void insertAt(T x, int index){
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
