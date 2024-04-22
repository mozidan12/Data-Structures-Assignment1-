#ifndef STUDENTCLASS_H
#define STUDENTCLASS_H
#include<iostream>
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
};

#endif