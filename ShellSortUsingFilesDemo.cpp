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

int main()
{
    // Outputting ShellSort sort by name Results
    Student::modifySortByName(true);
    vector<Student> v= readFromFile("students.txt");
    SortAndEvaluate(ShellSort,v,"SortByName.txt");
    return 0;
}
