#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// majority element - leetcode ques 169
// bruteforce approach - time complexity = O(n^2)
int bruteforce(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int freq = 0;
        for (int j = i; j < n; j++)
        {
            if (arr[i] == arr[j])
                freq++;
        }
        if (freq > n / 2)
            return arr[i];
    }
    return -1;
}

// optimized approach - applying sorting algorithm
// time complexity = O(nlogn + n) = O(n)
int optimized(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int freq = 1;
    for (int i = 1; i < n; i++)
    {
        (arr[i - 1] == arr[i]) ? freq++ : freq--;

        if (freq > n / 2)
            return arr[i];
    }
    return -1;
}

// moore vote algorithm - time complexity = O(n)
int moore(vector<int> &arr)
{
    int freq = 0, ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (freq == 0)
            ans = arr[i];

        (arr[i] == ans) ? freq++ : freq--;
    }
    return ans;
}

int main()
{
    vector<int> arr = {2, 2, 3, 2, 1, 2, 1, 2, 3, 2};
    cout << "majority element (via bruteforce): " << bruteforce(arr) << endl;
    cout << "majority element (via optimized): " << optimized(arr) << endl;
    cout << "majority element (via moore's voting algorithm): " << moore(arr) << endl;
    return 0;
}