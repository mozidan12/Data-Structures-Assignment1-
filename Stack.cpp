#include <iostream>
#include<cassert>
using namespace std;
template<typename T>
class stack{
  struct Node{
  T data;
  Node* next;
  };
  Node* top;
  int size;
  public:
  stack()
  {
    top=NULL;
    size=0;
  }
  bool isEmpty()
  {
    return size==0;
  }
  int stackSize()
  {
    return size;
  }
  void clear()
  {
    top=NULL;
    size=0;
  }
  void push(T x)
  {
    Node* t=new Node;
    t->data=x;
    t->next=top;
    top=t;
    if(isEmpty()){
      top=t;
      size++;
          }
    else 
     size++;  
  }
  T pop()
  { 
      assert(!isEmpty());
      Node* popNode= top;
      T value=popNode->data;
      top=top->next;
      size--;
      delete popNode;
      return value;
  }
  T Top(){
    assert(!isEmpty());
    return (top->data);
  }
  void print(){
  Node* topNode=top;
  if(topNode==NULL)
   cout<<"\nstack is empty";
   else{
  while(topNode!=NULL){
    cout<<topNode->data<<" ";
    topNode=topNode->next;
  }
  cout<<'\n';
  }
   }
};
int main(){
  stack <int> S;
  S.push(5);
  S.push(6);
  S.push(4);
  S.push(6);
  S.push(5);
  S.push(8);
  S.push(7);
  S.print();
  cout<<"top element is: "<<S.Top()<<"and the size is: "<<S.stackSize();
  cout<<"\ndelete top: "<<S.pop();
  S.clear();
  S.print();
}