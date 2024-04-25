#include <iostream>
#include <vector>
// this one consumes much more space but I like that it doesn't take any indexes as arguments lol
template<typename t>
void QuickSort(std::vector<t>& v) {
    if (v.size() <= 1) {
        return;
    }

    t pivot = v[v.size() / 2];
    std::vector<t> left;
    std::vector<t> right;

    for (int i = 0; i < v.size(); i++) {
        if (i == (v.size() / 2)) continue;

        if (v[i] < pivot) {
            left.push_back(v[i]);
        }
        else {
            right.push_back(v[i]);
        }
    }

    QuickSort(left);
    QuickSort(right);

    v = left;
    v.emplace_back(pivot);
    v.insert(v.end(), right.begin(), right.end());
}
int main(){
    std::vector<int>v{1, 12, 5, 26, 7, 14, 3, 7, 2};

    QuickSort(v);
    
    for(int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
}