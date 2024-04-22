#include "StudentClass.h"
using namespace std;
Student::Student(string id, string name, double gpa){
    ID = id;
    Name = name;
    GPA = gpa;
}
bool Student::operator > (Student& otherStudent){
    if(sortByName){
        return Name > otherStudent.Name;
    }
    else{
        return GPA > otherStudent.GPA;
    }
}
bool Student::operator < (Student& otherStudent){
    if(sortByName){
        return Name < otherStudent.Name;
    }
    else{
        return GPA < otherStudent.GPA;
    }
}
ostream& operator <<(ostream& os, const Student& student) {
    os << "Name: " << student.Name << ", GPA: " << student.GPA;
    return os;
}

