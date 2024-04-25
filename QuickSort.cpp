#include <iostream>
#include <vector>
template<typename t>
void QuickSort(std::vector<t> &v, int FirstIndex, int LastIndex){
    int TempLeft = FirstIndex;
    int TempRight = LastIndex;

    t pivot = v[(FirstIndex + LastIndex) / 2];
    while(FirstIndex <= LastIndex){

        while(v[FirstIndex] < pivot)
            FirstIndex++;

        while(v[LastIndex] > pivot)
            LastIndex--;

        if(FirstIndex <= LastIndex){
            swap(v[FirstIndex], v[LastIndex]);
            FirstIndex++;
            LastIndex--;
        }
    }

    if(TempLeft < LastIndex)
        QuickSort(v, TempLeft, LastIndex);

    if(FirstIndex < TempRight)
        QuickSort(v, FirstIndex, TempRight);

}
int main(){
    std::vector<int>v{1, 12, 5, 26, 7, 14, 3, 7, 2};

    QuickSort(v,0,v.size()-1);
    
    for(int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
}