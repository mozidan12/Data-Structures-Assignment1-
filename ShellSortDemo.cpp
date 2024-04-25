#include <iostream>
#include"StudentClass.h"
using namespace std;
#include<bits/stdc++.h>


template<typename T>
void ShellSort(vector<T> &v){
    int n = v.size();
    for(int gap = n/2; gap > 0; gap = gap/2){
        for(int i = gap; i<n;i++){
            T curr = v[i];
            int pos = i;
            while(pos > 0 and v[pos-gap] > curr){
                
                v[pos]  = v[pos-gap];
                pos -=gap;
            }
            v[pos] = curr;
        }
    }
}

template<typename T>
void bubbleSort(vector<T> &v){
    int n = v.size();
    for (int i = 0; i < n-1; ++i) {
        bool flag = false;
        for (int j = 0; j < n-i-1; ++j) {
            if(v[j] > v[j+1]) {
                swap(v[j], v[j + 1]);
                flag = true;
            }
        }
        if(!flag) // array is sorted
            break;
    }
}

template<typename T>
void selection_sort(vector<T> &v){
    int n = v.size();
    for (int i = 0; i < n-1; ++i) {
        int minIdx = i;
        for (int j = i+1; j < n; ++j) {
            if(v[j] < v[minIdx])
                minIdx = j;
        }
        swap(v[i], v[minIdx]);
    }
}

template<typename T>
void insertion_sort(vector<T> &v){
    int n = v.size();
    for (int i = 1; i < n; ++i) {   // 40, 50, 60, 30, 10, 20
        T key = v[i]; //60
        int j = i-1;  //1
        while(j >= 0 && v[j] > key){
            v[j+1] = v[j];
            j -= 1;
        }
        v[j+1] = key;
    }
}


bool Student::sortByName = true;
int main()
{
    
    Student student1("20220103", "Hamada", 3.9);
    Student student2("20220100", "Ahmed", 3.2);
    Student student3("20220101", "Basheer", 3.7);
    Student student4("20220102", "Carlo", 3.4);
    Student student5("20220104", "Danny", 3.6);
    Student student6("20220105", "Emad", 3.8);
    vector<Student> v= {student1, student3, student2, student4, student6, student5};
    insertion_sort(v);
    for(auto x: v){
        cout<<x<<endl;
    }

    return 0;
}
