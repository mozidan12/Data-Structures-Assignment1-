#include <iostream>
#include <cassert>
using namespace std;
const int MAX_SIZE =200;

template<typename T>
class arrayQueue{
    int front;
    int back;
    int length;
    T queueArray[MAX_SIZE];
public:
    arrayQueue(){
        front = 0;
        back = MAX_SIZE - 1;
        length = 0;
    }
    int queueSize(){
        return length;
    }
    int queueMaxSize(){
        return MAX_SIZE;
    }
    bool isEmpty(){
        return length==0;
    }
    bool isFull(){
        return length == MAX_SIZE;
    }
    void enqueue(T element){
        if(isFull()){
            cout<<"Queue Full";
            return;
        }
        back = (back + 1)%MAX_SIZE;
        queueArray[back] = element;
        length++;
        
    }
    T dequeue(){
        assert(!isEmpty());
        T element  = queueArray[front];
        front = (front + 1)%MAX_SIZE;
        length--;
        return element;
        
    }
    T first(){
        assert(!isEmpty());
        return queueArray[front];
    }
    void clear(){
        front = 0;
        back = MAX_SIZE - 1;
        length = 0;
    }
    void print(){
        for(int i =front; i != back; i = (i + 1)%MAX_SIZE){
            cout<<queueArray[i]<<" ";
        }
        cout<<queueArray[back]<<endl;
    }
};

int main()
{
    arrayQueue<int> q;
    q.enqueue(5);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(7);
    q.print();
    cout<<"current front element: "<<q.first()<<" current length of queue:"<<q.queueSize()<<endl;
    q.dequeue();
    q.print();
    cout<<"current front element: "<<q.first()<<" current length of queue:"<<q.queueSize()<<endl;

    return 0;
}