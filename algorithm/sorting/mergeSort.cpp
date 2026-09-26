#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void merge(vector<int> &arr, int left, int mid, int right)
{
    vector<int> L, R;
    for (int i = left; i <= mid; i++)
    {
        L.push_back(arr[i]);
    }
    for (int j = mid + 1; j <= right; j++)
    {
        R.push_back(arr[j]);
    }
    L.push_back(INT_MAX);
    R.push_back(INT_MAX);

    int i = 0, j = 0;
    for (int k = left; k <= right; k++)
    {
        if (L[i] < R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
    }
}

void mergeSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
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

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int value : arr)
    {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}