#ifndef STUDENTCLASS_H
#define STUDENTCLASS_H
#include<iostream>
#include<vector>
#include<fstream>
#include <chrono>
// #include"StudentClass.cpp"
using namespace std;
class Student{
    string ID;
    string Name;
    double GPA;
    static bool sortByName;
public:
    Student(string id, string name, double gpa);
    bool operator > (Student& otherStudent);
    bool operator < (Student& otherStudent);
    friend ostream& operator<<(ostream& os, const Student& student);
    static void modifySortByName(bool flag);
};
vector<Student> readFromFile(string fileName);
template<typename T>
void SortAndEvaluate(void (*func)(vector<T>&), vector<T> &v, string filename){
    ofstream file(filename, ios::app);
    auto start = chrono::high_resolution_clock::now();
    func(v);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    file<<"Running Time: "<<duration<<" microseconds"<<endl<<endl;
    for(auto x:v){
        file<<x;
    }
}

#endif
