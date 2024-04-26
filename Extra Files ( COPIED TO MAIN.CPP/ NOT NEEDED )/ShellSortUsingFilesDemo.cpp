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

int main()
{
    // Outputting ShellSort sort by name Results
    Student::modifySortByName(true);
    vector<Student> v= readFromFile("students.txt");
    SortAndEvaluate(ShellSort,v,"SortByName.txt");
    return 0;
}
