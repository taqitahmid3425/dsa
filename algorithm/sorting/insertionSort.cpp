#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j > -1 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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

    insertionSort(arr);

    cout << "Sorted array: ";
    for (int value : arr)
    {
        cout << value << " ";
    }
    cout << endl;
    return 0;
}