#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void selectionSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            minIdx = (arr[minIdx] > arr[j]) ? j : minIdx;
        }
        swap(arr[i], arr[minIdx]);
    }
}

int main()
{
    vector<int> arr = {68, 6, 23, 47, 4, 80, 3, 36, 13};
    cout << "Unsorted array: ";
    for (int value : arr)
    {
        cout << value << " ";
    }
    cout << endl;

    selectionSort(arr);

    cout << "Sorted array: ";
    for (int value : arr)
    {
        cout << value << " ";
    }
    cout << endl;
    return 0;
}