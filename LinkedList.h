//
// Created by farah on 22/04/2024.
//

#ifndef DATA_STRUCTURES_ASSIGNMENT1_LINKEDLIST_H
#define DATA_STRUCTURES_ASSIGNMENT1_LINKEDLIST_H

class Node{
public:
    int data;
    Node *next;
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
    int removeAt(int index);
    int length();


};


#endif //DATA_STRUCTURES_ASSIGNMENT1_LINKEDLIST_H
