#include <iostream>
#include <vector>
//==================================
template<typename t>
void QuickSort(std::vector<t> &v, int FirstIndex, int LastIndex){

    int TempLeft = FirstIndex;
    int TempRight = LastIndex;

    // Get the pivot element (middle element) 
    t pivot = v[(FirstIndex + LastIndex) / 2];


    while(FirstIndex <= LastIndex){

        // Loop throught the vector until we find an element that is smaller than the pivot
        while(v[FirstIndex] < pivot)
            FirstIndex++;

        // Loop throught the vector until we find an element that is greater than the pivot
        while(v[LastIndex] > pivot)
            LastIndex--;

        // if the two indexes are still in the right order, swap the elements
        if(FirstIndex <= LastIndex){
            std::swap(v[FirstIndex], v[LastIndex]);
            FirstIndex++;
            LastIndex--;
        }
    }

    // Recursively call the function to sort the left and right vectors
    if(TempLeft < LastIndex)
        QuickSort(v, TempLeft, LastIndex);

    if(FirstIndex < TempRight)
        QuickSort(v, FirstIndex, TempRight);

}
//==================================
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
//==================================
int main(){
    std::vector<int>v{1, 12, 5, 26, 7, 14, 3, 7, 2};
    QuickSort(v,0,v.size()-1);
    for(int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";

    std::cout << std::endl;
//==================================
    v = {1, 12, 5, 26, 7, 14, 3, 7, 2};
    QuickSort(v);
    for(int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
}