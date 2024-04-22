/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
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
    ShellSort(v);
    for(auto x: v){
        cout<<x<<endl;
    }

    return 0;
}
