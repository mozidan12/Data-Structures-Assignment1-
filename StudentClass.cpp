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
    os <<student.Name<<endl<<student.ID<<endl<<student.GPA<<endl<<endl;
    return os;
}
void Student::modifySortByName(bool flag){
    sortByName = flag;
}
bool Student::sortByName;
vector<Student> readFromFile(string fileName){
    vector<Student> students;
    ifstream studentsFile(fileName);
    if(!studentsFile.is_open()){
        cout<<"error opening the file";
        return students;
    }
    string dummy;
    int numStudents;
    studentsFile>>numStudents;
    getline(studentsFile,dummy);
    for(int i =0; i<numStudents; i++){
        string name;
        string id;
        string gpas;
        getline(studentsFile,name);
        getline(studentsFile,id);
        getline(studentsFile,gpas);
        name.pop_back();
        id.pop_back();
        gpas.pop_back();
        double gpa = stod(gpas);
        Student newStudent(id, name, gpa);
        students.push_back(newStudent);
    }
    return students;
}
