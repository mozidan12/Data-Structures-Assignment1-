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

template<typename t>
void QuickSort(std::vector<t>& v) {

    //Base case
    if (v.size() <= 1) {
        return;
    }

    // Get the pivot element (middle element)
    // And create two vectors to store the left and right elements
    t pivot = v[v.size() / 2];
    std::vector<t> left;
    std::vector<t> right;

    // Insert the elements into the left and right vectors
    for (int i = 0; i < v.size(); i++) {
        if (i == (v.size() / 2)) continue;

        if (v[i] < pivot) {
            left.emplace_back(v[i]);
        }
        else {
            right.emplace_back(v[i]);
        }
    }

    // Recursively call the function to sort the left and right vectors
    QuickSort(left);
    QuickSort(right);

    // Merge the left and right vectors
    v = left;
    v.emplace_back(pivot);
    v.insert(v.end(), right.begin(), right.end());
}
template <typename T>
void Merge(std::vector<T> &v, std::vector<T> &left, std::vector<T> &right){

    int i = 0; // Index to loop through left vector
    int j = 0; // Index to loop through right vector
    int k = 0; // Index to loop through the main vector

    // Loop through the left and right vectors and compare the elements
    // To sort them in the main vector
    while(i < left.size() && j < right.size()){
        if(left[i] < right[j]){
            v[k] = left[i];
            i++;
        }
        else{
            v[k] = right[j];
            j++;
        }
        k++;
    }

    // Incase the first loop ends before the two loops are done
    // We need to loop through the remaining elements in the not empty vector 
    while(i < left.size()){
        v[k] = left[i];
        i++;
        k++;
    }
    while(j < right.size()){
        v[k] = right[j];
        j++;
        k++;
    }
}
//==================================
template <typename T>
void MergeSort(std::vector<T> &v){
    
    // Base case
    if (v.size() <= 1) {
        return;
    }

    int mid = v.size() / 2;

    // Create two vectors to store the left and right elements
    std::vector<T> left;
    std::vector<T> right;

    // Insert the elements into the left and right vectors
    for (int i = 0; i < v.size(); i++) {
        if (i < mid) {
            left.emplace_back(v[i]);
        }
        else {
            right.emplace_back(v[i]);
        }
    }

    // Recursively call the function to sort the left and right vectors
    MergeSort(left);
    MergeSort(right);
    Merge(v, left, right);
}

int main(){
    cout << "Choose input file: ";

    string input_filename;
    cin >> input_filename;

    vector<Student> v = readFromFile(input_filename);
    cout << "Choose output file: ";
    string output_filename;
    cin >> output_filename;

    bool sort;
    cout << "Choose whether to sort by name or gpa\n";
    cout << "0-Gpa\n1-Name\n";
    cin >> sort;
    
    if(sort){
        Student::modifySortByName(true);
    }
    else{
        Student::modifySortByName(false);
    }
    while(true){
        cout << "Choose sorting algorithm: ";
        cout << "1-Shell Sort\n2-Insertion Sort\n3-Selection Sort\n4-Quick Sort\n5-Bubble Sort\n6-Merge Sort\n7-End Program\n";
        
        int choice;
        cin >> choice;

        ofstream file(output_filename, ios::app);
        switch(choice){
            case(1):
            file << "Algorithm: Shell Sort\n";
            SortAndEvaluate(ShellSort, v, output_filename);
            break;

            case(2):
            file << "Algorithm: Insertion Sort\n";
            SortAndEvaluate(insertion_sort, v, output_filename);
            break;

            case(3):
            file << "Algorithm: Selection Sort\n";
            SortAndEvaluate(selection_sort, v, output_filename);
            break; 

            case(4):
            file << "Algorithm: Quick Sort\n";
            SortAndEvaluate(QuickSort, v, output_filename);
            break;

            case(5):
            file << "Algorithm: Bubble Sort\n";
            SortAndEvaluate(bubbleSort,v,output_filename);
            break;

            case(6):
            file << "Algorithm: Merge Sort\n";
            SortAndEvaluate(MergeSort, v, output_filename);
            break;

            case(7):
            return 0;
        }
    }
    return 0;
}
