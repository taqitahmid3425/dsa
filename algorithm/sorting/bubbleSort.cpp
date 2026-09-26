#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bubbleSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < arr.size() - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) return;
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

    bubbleSort(arr);

    cout << "Sorted array: ";
    for (int value : arr)
    {
        cout << value << " ";
    }
    cout << endl;
    return 0;
}