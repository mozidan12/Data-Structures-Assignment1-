#include <iostream>
#include<cassert>

using namespace std;

template<typename T>
class stack {
    struct Node {
        T data;
        Node *next;
    };
    Node *top;
    int size;
public:
    stack() {
        top = NULL;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    int stackSize() {
        return size;
    }

    void clear() {
        while (top != nullptr) {
            pop();
        }

    }

    void push(T x) {
        Node *t = new Node;
        t->data = x;
        t->next = top;
        top = t;
    }

    T pop() {
        assert(!isEmpty());
        Node *popNode = top;
        T value = popNode->data;
        top = top->next;
        size--;
        delete popNode;
        return value;
    }

    T peek() {
        assert(!isEmpty());
        Node *peekNode = top;
        T value = peekNode->data;
        return value;
    }

    T Top() {
        assert(!isEmpty());
        return (top->data);
    }

    void print() {
        Node *topNode = top;
        if (topNode == NULL)
            cout << "\nstack is empty";
        else {
            while (topNode != NULL) {
                cout << topNode->data << " ";
                topNode = topNode->next;
            }
            cout << '\n';
        }
    }
};
