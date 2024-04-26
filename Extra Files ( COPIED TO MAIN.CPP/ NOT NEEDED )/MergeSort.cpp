#include <iostream>
#include <vector>
//==================================
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
//==================================
int main(){
    std::vector<int>v{1, 12, 5, 26, 7, 14, 3, 7, 2};

    MergeSort(v);
    
    for(int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
}