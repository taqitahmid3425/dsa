#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int partition(vector<int> &arr, int left, int right)
{
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[right]);
    return i + 1;
}

void quickSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int pi = partition(arr, left, right);
        quickSort(arr, left, pi - 1);
        quickSort(arr, pi + 1, right);
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

    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int value : arr)
    {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}