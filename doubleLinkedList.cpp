#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node<T>* prev;
    Node(T value) : data(value), next(NULL), prev(NULL) {}
};


template <typename T>
class DoubleLinkedList {
private:
    Node<T>* head;
    int size;
public:
    DoubleLinkedList(): head(NULL), size(0){}

    bool isEmpty(){
        return head == NULL;
    }

    int linkedListSize (){
        return size;
    }

    void insertAtHead (T value){
        Node<T>* newNode = new Node(value);
        if (!isEmpty()){
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
        ++size;
    }

    void insertAtTail (T value){
        if (isEmpty()){
            insertAtHead(value);
            return;
        }
        Node<T>* current = head;
        Node<T>* newNode = new Node(value);
        while (current->next != NULL)
            current = current->next;
        current->next = newNode;
        newNode->prev = current;
        ++size;
    }

    void insertAt (T value, int index){
//        if(index >= size || index < 0){
//            cout << "Index " << index << " is out of range\n";
//            return;
//        }
        if (isEmpty() || index == 0){
            insertAtHead(value);
            return;
        }
        int currentIndex = 0;
        Node<T>* current = head;
        Node<T>* newNode = new Node(value);
        while (currentIndex < index) {
            current = current->next;
            currentIndex++;
        }
        newNode->prev = current->prev;  // pointing the newNode prev pointer to the node before the current
        current->prev->next = newNode;  // pointing the pointer next of the node before the current to newNode
        newNode->next = current;
        current->prev = newNode;
        ++size;
    }

    void removeAtHead (){
        if(isEmpty()){
            cout << "The list is empty\n";
            return;
        }
        Node<T> *temp = head;
        if(head->next == NULL){
            head = NULL;
        }
        else{
            head = head->next;
            head->prev = NULL;
        }
        delete temp;
        --size;
    }

    void removeAtTail (){
        if(isEmpty() || head->next == NULL) {
            removeAtHead();
            return;
        }
        Node<T> *temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->prev->next = NULL;    // setting the pointer next of the node before the current node to NULL
        delete temp;
        --size;
    }

    void removeAt (int index) {
//        if(index >= size || index < 0){
//            cout << "Index " << index << " is out of range\n";
//            return;
//        }
        if (isEmpty() || index == 0){
            removeAtHead();
            return;
        }
        if(index == size-1){  //last element in the list
            removeAtTail();
            return;
        }
        int currentIndex = 0;
        Node<T>* current = head;
        while(currentIndex < index){
            ++currentIndex;
            current = current->next;
        }
        current->prev->next = current->next;    // pointing the pointer next of the node before current to node after current
        current->next->prev = current->prev;    // pointing the pointer prev of the node after current to node before current
        delete current;
        --size;
    }

    void replaceAt (T value, int index){
        if(isEmpty()){
            cout << "The list is empty\n";
            return;
        }
//        if(index >= size || index < 0){
//            cout << "Index " << index << " is out of range\n";
//            return;
//        }
        int currentIndex = 0;
        Node<T>* current = head;
        while (currentIndex < index) {
            current = current->next;
            currentIndex++;
        }
        current->data = value;
    }

    T retrieveAt (int index){
//        if(index >= size || index < 0){
//            cout << "Index " << index << " is out of range\n";
//            return NULL;
//        }
        int currentIndex = 0;
        Node<T>* current = head;
        while (currentIndex < index) {
            current = current->next;
            currentIndex++;
        }
        return current->data;
    }

    void swap (int firstItemIdx, int secondItemIdx){    // swap two nodes without swapping data.
        if(firstItemIdx >= size || firstItemIdx < 0
        || secondItemIdx >= size || secondItemIdx < 0){
            cout << "Index is out of range\n";
            return;
        }
        if(firstItemIdx == secondItemIdx) return;
        T firstData = retrieveAt(firstItemIdx);
        T secondData = retrieveAt(secondItemIdx);
        insertAt(firstData, secondItemIdx);
        insertAt(secondData, firstItemIdx);
        removeAt(firstItemIdx+1);
        removeAt(secondItemIdx+1);
    }



    bool isExist (T value){
        Node<T> *current = head;
        while (current != NULL && current->data != value)
            current = current->next;
        return (current != NULL);
    }

    bool isItemAtEqual (T value, int index){
        if(index >= size || index < 0){
            cout << "Index " << index << " is out of range\n";
            return false;
        }
        int currentIndex = 0;
        Node<T>* current = head;
        while (currentIndex < index) {
            current = current->next;
            currentIndex++;
        }
        return (current->data == value);
    }

    void clear(){
        head = NULL;
        size = 0;
    }

    void print(){
        if(!isEmpty()){
            Node<T> *current = head;
//            Node<T> *temp;  ////
            while (current != NULL) {
                cout << current->data << " ";
//                temp = current;   ////
                current = current->next;
            }
//            current = temp;    ////
//            cout << endl;   ////
//            while (current != NULL) {
//                cout << current->data << " ";
//                current = current->prev;
//            }
        }
        else cout << "The list is empty";
    }
};


int main() {
    DoubleLinkedList<int> dll;
    dll.insertAtTail(23);
    dll.insertAtTail(85);
    dll.insertAtTail(19);
    dll.insertAtTail(62);
    dll.insertAt(99, 3);
    dll.removeAtTail();
    dll.removeAtHead();
    dll.insertAtHead(37);
    dll.removeAt(3);
    dll.insertAtTail(53);
    dll.insertAtTail(49);

    dll.replaceAt(20, 2);
    dll.swap(2, 4);

    dll.print();
    cout << endl << ((dll.isItemAtEqual(85, 1))? "yes" : "no");
    cout << endl << dll.linkedListSize();
    cout << endl << dll.retrieveAt(3);
}
