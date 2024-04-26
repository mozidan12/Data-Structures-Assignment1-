#include <iostream>
#include "LinkedList.h"
#include "doubleLinkedList.cpp"
#include "CircularList.h"
#include "ListQueue.cpp"
#include "Stack.cpp"
using namespace std;

int main() {
    int choice;
    do {
        cout << "Menu:" << endl;
        cout << "1. Linked List" << endl;
        cout << "2. Doubly Linked List" << endl;
        cout << "3. Circular Linked List" << endl;
        cout << "4. Queue" << endl;
        cout << "5. Stack" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                LinkedList<int> myList;
                int choice2;
                do {
                    cout << "Linked List Menu:" << endl;
                    cout << "1. InsertAtHead" << endl;
                    cout << "2. InsertAtTail" << endl;
                    cout << "3. InsertAt" << endl;
                    cout << "4. RemoveAtHead" << endl;
                    cout << "5. RemoveAtTail" << endl;
                    cout << "6. RemoveAt" << endl;
                    cout << "7. RetrieveAt" << endl;
                    cout << "8. ReplaceAt" << endl;
                    cout << "9. IsExist" << endl;
                    cout << "10. IsItemAtEqual" << endl;
                    cout << "11. Swap" << endl;
                    cout << "12. IsEmpty" << endl;
                    cout << "13. Length" << endl;
                    cout << "14. Clear" << endl;
                    cout << "15. Print" << endl;
                    cout << "0. Exit" << endl;
                    cout << "Enter your choice: ";
                    cin >> choice2;

                    switch (choice2) {
                        case 1: {
                            int newValue;
                            cout << "Enter the value to insert at the head: ";
                            cin >> newValue;
                            myList.insertAtHead(newValue);
                            break;
                        }
                        case 2: {
                            int newValue;
                            cout << "Enter the value to insert at the tail: ";
                            cin >> newValue;
                            myList.insertAtTail(newValue);
                            break;
                        }
                        case 3: {
                            int newValue, index;
                            cout << "Enter the value: ";
                            cin >> newValue;
                            cout << "Enter index: ";
                            cin >> index;
                            myList.insertAt(newValue, index);
                            break;
                        }
                        case 4:
                            cout << "Removed head" << endl;
                            myList.removeAtHead();
                            break;
                        case 5:
                            cout << "Removed tail" << endl;
                            myList.removeAtTail();
                            break;
                        case 6: {
                            int index;
                            cout << "Remove at index: ";
                            cin >> index;
                            myList.removeAt(index);
                            break;
                        }
                        case 7: {
                            int index;
                            cout << "Retrieve at index: ";
                            cin >> index;
                            myList.retrieveAt(index);
                            break;
                        }
                        case 8: {
                            int newValue, index;
                            cout << "Enter new value: ";
                            cin >> newValue;
                            cout << "Enter index: ";
                            cin >> index;
                            myList.replaceAt(newValue, index);
                            break;
                        }
                        case 9: {
                            int value;
                            cout << "Enter value: ";
                            cin >> value;
                            if (myList.exists(value))
                                cout << "Exists" << endl;
                            else
                                cout << "Doesn't exist" << endl;
                            break;
                        }
                        case 10: {
                            int index, value;
                            cout << "Enter value: ";
                            cin >> value;
                            cout << "Enter index: ";
                            cin >> index;
                            if (myList.equals(index, value))
                                cout << "Equal" << endl;
                            else
                                cout << "Not equal" << endl;
                            break;
                        }
                        case 11: {
                            int index1, index2;
                            cout << "Enter first index: ";
                            cin >> index1;
                            cout << "Enter second index: ";
                            cin >> index2;
                            myList.swap(index1, index2);
                            break;
                        }
                        case 12:
                            if (myList.isEmpty())
                                cout << "Empty" << endl;
                            else
                                cout << "Not empty" << endl;
                            break;
                        case 13:
                            cout << "Length: " << myList.length() << endl;
                            break;
                        case 14:
                            myList.clear();
                            cout << "List cleared" << endl;
                            break;
                        case 15:
                            cout << "List: ";
                            myList.display();
                            break;
                        case 0:
                            cout << "Closing Linked List menu" << endl;
                            break;
                        default:
                            cout << "Invalid choice. Please select from the menu." << endl;
                            break;
                    }
                } while (choice2 != 0);
                break;
            }
            case 2: {
                CircularList<int> myList;
                int choice2;
                do {
                    cout << "Circular Linked List Menu:" << endl;
                    cout << "1. InsertAtHead" << endl;
                    cout << "2. InsertAtTail" << endl;
                    cout << "3. InsertAt" << endl;
                    cout << "4. RemoveAtHead" << endl;
                    cout << "5. RemoveAtTail" << endl;
                    cout << "6. RemoveAt" << endl;
                    cout << "7. RetrieveAt" << endl;
                    cout << "8. ReplaceAt" << endl;
                    cout << "9. IsExist" << endl;
                    cout << "10. IsItemAtEqual" << endl;
                    cout << "11. Swap" << endl;
                    cout << "12. IsEmpty" << endl;
                    cout << "13. Length" << endl;
                    cout << "14. Clear" << endl;
                    cout << "15. Print" << endl;
                    cout << "0. Exit" << endl;
                    cout << "Enter your choice: ";
                    cin >> choice2;

                    switch (choice2) {
                        case 1: {
                            int newValue;
                            cout << "Enter the value to insert at the head: ";
                            cin >> newValue;
                            myList.insertAtHead(newValue);
                            break;
                        }
                        case 2: {
                            int newValue;
                            cout << "Enter the value to insert at the tail: ";
                            cin >> newValue;
                            myList.insertAtTail(newValue);
                            break;
                        }
                        case 3: {
                            int newValue, index;
                            cout << "Enter the value: ";
                            cin >> newValue;
                            cout << "Enter index: ";
                            cin >> index;
                            myList.insertAt(newValue, index);
                            break;
                        }
                        case 4:
                            cout << "Removed head" << endl;
                            myList.removeAtHead();
                            break;
                        case 5:
                            cout << "Removed tail" << endl;
                            myList.removeAtTail();
                            break;
                        case 6: {
                            int index;
                            cout << "Remove at index: ";
                            cin >> index;
                            myList.removeAt(index);
                            break;
                        }
                        case 7: {
                            int index;
                            cout << "Retrieve at index: ";
                            cin >> index;
                            myList.retrieveAt(index);
                            break;
                        }
                        case 8: {
                            int newValue, index;
                            cout << "Enter new value: ";
                            cin >> newValue;
                            cout << "Enter index: ";
                            cin >> index;
                            myList.replaceAt(newValue, index);
                            break;
                        }
                        case 9: {
                            int value;
                            cout << "Enter value: ";
                            cin >> value;
                            if (myList.exists(value))
                                cout << "Exists" << endl;
                            else
                                cout << "Doesn't exist" << endl;
                            break;
                        }
                        case 10: {
                            int index, value;
                            cout << "Enter value: ";
                            cin >> value;
                            cout << "Enter index: ";
                            cin >> index;
                            if (myList.equals(index, value))
                                cout << "Equal" << endl;
                            else
                                cout << "Not equal" << endl;
                            break;
                        }
                        case 11: {
                            int index1, index2;
                            cout << "Enter first index: ";
                            cin >> index1;
                            cout << "Enter second index: ";
                            cin >> index2;
                            myList.swap(index1, index2);
                            break;
                        }
                        case 12:
                            if (myList.isEmpty())
                                cout << "Empty" << endl;
                            else
                                cout << "Not empty" << endl;
                            break;
                        case 13:
                            cout << "Length: " << myList.length() << endl;
                            break;
                        case 14:
                            myList.clear();
                            cout << "List cleared" << endl;
                            break;
                        case 15:
                            cout << "List: ";
                            myList.display();
                            break;
                        case 0:
                            cout << "Closing Linked List menu" << endl;
                            break;
                        default:
                            cout << "Invalid choice. Please select from the menu." << endl;
                            break;
                    }
                } while (choice2 != 0);
                break;
            }
            case 3: {
                DoubleLinkedList<int> myList;
                int choice2;
                do {
                    cout << "Doubly Linked List Menu:" << endl;
                    cout << "1. InsertAtHead" << endl;
                    cout << "2. InsertAtTail" << endl;
                    cout << "3. InsertAt" << endl;
                    cout << "4. RemoveAtHead" << endl;
                    cout << "5. RemoveAtTail" << endl;
                    cout << "6. RemoveAt" << endl;
                    cout << "7. RetrieveAt" << endl;
                    cout << "8. ReplaceAt" << endl;
                    cout << "9. IsExist" << endl;
                    cout << "10. IsItemAtEqual" << endl;
                    cout << "11. Swap" << endl;
                    cout << "12. IsEmpty" << endl;
                    cout << "13. Length" << endl;
                    cout << "14. Clear" << endl;
                    cout << "15. Print" << endl;
                    cout << "0. Exit" << endl;
                    cout << "Enter your choice: ";
                    cin >> choice2;

                    switch (choice2) {
                        case 1: {
                            int newValue;
                            cout << "Enter the value to insert at the head: ";
                            cin >> newValue;
                            myList.insertAtHead(newValue);
                            break;
                        }
                        case 2: {
                            int newValue;
                            cout << "Enter the value to insert at the tail: ";
                            cin >> newValue;
                            myList.insertAtTail(newValue);
                            break;
                        }
                        case 3: {
                            int newValue, index;
                            cout << "Enter the value: ";
                            cin >> newValue;
                            cout << "Enter index: ";
                            cin >> index;
                            myList.insertAt(newValue, index);
                            break;
                        }
                        case 4:
                            cout << "Removed head" << endl;
                            myList.removeAtHead();
                            break;
                        case 5:
                            cout << "Removed tail" << endl;
                            myList.removeAtTail();
                            break;
                        case 6: {
                            int index;
                            cout << "Remove at index: ";
                            cin >> index;
                            myList.removeAt(index);
                            break;
                        }
                        case 7: {
                            int index;
                            cout << "Retrieve at index: ";
                            cin >> index;
                            myList.retrieveAt(index);
                            break;
                        }
                        case 8: {
                            int newValue, index;
                            cout << "Enter new value: ";
                            cin >> newValue;
                            cout << "Enter index: ";
                            cin >> index;
                            myList.replaceAt(newValue, index);
                            break;
                        }
                        case 9: {
                            int value;
                            cout << "Enter value: ";
                            cin >> value;
                            if (myList.isExist(value))
                                cout << "Exists" << endl;
                            else
                                cout << "Doesn't exist" << endl;
                            break;
                        }
                        case 10: {
                            int index, value;
                            cout << "Enter value: ";
                            cin >> value;
                            cout << "Enter index: ";
                            cin >> index;
                            if (myList.isItemAtEqual(value, index))
                                cout << "Equal" << endl;
                            else
                                cout << "Not equal" << endl;
                            break;
                        }
                        case 11: {
                            int index1, index2;
                            cout << "Enter first index: ";
                            cin >> index1;
                            cout << "Enter second index: ";
                            cin >> index2;
                            myList.swap(index1, index2);
                            break;
                        }
                        case 12:
                            if (myList.isEmpty())
                                cout << "Empty" << endl;
                            else
                                cout << "Not empty" << endl;
                            break;
                        case 13:
                            cout << "Length: " << myList.length() << endl;
                            break;
                        case 14:
                            myList.clear();
                            cout << "List cleared" << endl;
                            break;
                        case 15:
                            cout << "List: ";
                            myList.print();
                            break;
                        case 0:
                            cout << "Closing Linked List menu" << endl;
                            break;
                        default:
                            cout << "Invalid choice. Please select from the menu." << endl;
                            break;
                    }
                } while (choice2 != 0);
                break;
            }
            case 4: {
                Queue<int> myQueue;
                int choice2;
                do {
                    cout << "Queue Menu:" << endl;
                    cout << "1. Enqueue" << endl;
                    cout << "2. Dequeue" << endl;
                    cout << "3. IsEmpty" << endl;
                    cout << "4. Size" << endl;
                    cout << "5. Clear" << endl;
                    cout << "6. First" << endl;
                    cout << "7. Display" << endl;
                    cout << "0. Exit" << endl;
                    cout << "Enter your choice: ";
                    cin >> choice2;

                    switch (choice2) {
                        case 1:
                            cout << "Enter value to enqueue: ";
                            int value; cin >> value; cout << endl;
                            myQueue.enqueue(value);
                            break;
                        case 2:
                            myQueue.dequeue();
                            break;
                        case 3:
                            if(myQueue.isEmpty()) cout <<"Yes, queue is empty\n";
                            else cout <<"No, queue is not empty\n";
                            break;
                        case 4:
                            cout << "Queue size: " << myQueue.queueSize() << endl;
                            break;
                        case 5:
                            cout << "Clearing...\n";
                            myQueue.clear();
                            break;
                        case 6:
                            cout << "First element: " << myQueue.first() << endl;
                            break;
                        case 7:
                            myQueue.print(); cout << endl;
                            break;
                        case 0:
                            cout << "Closing Queue menu" << endl;
                            break;
                        default:
                            cout << "Invalid choice. Please select from the menu." << endl;
                            break;
                    }
                }while(choice2 != 0);
                break;
            }
            case 5: {
                stack<int> myStack;
                int choice2;
                do {
                    cout << "Stack Menu:" << endl;
                    cout << "1. Push" << endl;
                    cout << "2. Pop" << endl;
                    cout << "3. IsEmpty" << endl;
                    cout << "4. Size" << endl;
                    cout << "5. Clear" << endl;
                    cout << "6. First" << endl;
                    cout << "7. Display" << endl;
                    cout << "0. Exit" << endl;
                    cout << "Enter your choice: ";
                    cin >> choice2;

                    switch (choice2) {
                        case 1:
                            cout << "Enter value to push: ";
                            int value; cin >> value; cout << endl;
                            myStack.push(value);
                            break;
                        case 2:
                            cout << "Popping...\n";
                            myStack.pop();
                            break;
                        case 3:
                            if(myStack.isEmpty()) cout <<"Yes, stack is empty\n";
                            else cout <<"No, stack is not empty\n";
                            break;
                        case 4:
                            cout << "Stack size: " << myStack.stackSize() << endl;
                            break;
                        case 5:
                            cout << "Clearing...\n";
                            myStack.clear();
                            break;
                        case 6:
                            cout << "First element: " << myStack.Top() << endl;
                            break;
                        case 7:
                            myStack.print(); cout << endl;
                            break;
                        case 0:
                            cout << "Closing Stack menu" << endl;
                            break;
                        default:
                            cout << "Invalid choice. Please select from the menu." << endl;
                            break;
                    }
                }while(choice2 != 0);
                break;
            }
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please select from the menu." << endl;
                break;
        }
    }while (choice != 0);
    return 0;

}