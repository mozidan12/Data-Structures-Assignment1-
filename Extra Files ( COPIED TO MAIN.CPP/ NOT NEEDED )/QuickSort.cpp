#include <iostream>
#include <vector>
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
    std::vector<int> v = {1, 12, 5, 26, 7, 14, 3, 7, 2};
    QuickSort(v);
    for(int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
}