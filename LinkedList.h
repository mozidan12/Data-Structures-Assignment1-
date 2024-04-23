//
// Created by farah on 22/04/2024.
//

#ifndef DATA_STRUCTURES_ASSIGNMENT1_LINKEDLIST_H
#define DATA_STRUCTURES_ASSIGNMENT1_LINKEDLIST_H
#include <iostream>
class Node{
public:
    int data;
    Node *next;
    friend std::ostream& operator<<(std::ostream& os, const Node* n) {
        os << n->data;
        return os;
    }
};
class LinkedList {
private:
    Node *first;
public:
    LinkedList(): first{}{}
    LinkedList(int A[], int n);
    ~LinkedList();

    void display();

    void insertAt(int index, int x);
    void insertAtHead(int x);
    void insertAtTail(int x);

    void removeAt(int index);
    void removeAtHead();
    void removeAtTail();

    void replaceAt(int x, int index);
    Node* retrieveAt(int index);
    bool exists(int x);

    bool equals(int index, int x);
    void swap(int firstIndex, int secondIndex);

    int length();
    bool isEmpty();
    void clear();


};


#endif //DATA_STRUCTURES_ASSIGNMENT1_LINKEDLIST_H
