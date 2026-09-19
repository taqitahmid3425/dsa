#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// brute force approce - time complexity: O(n^2)
int maxSubarray(vector<int> &arr)
{
    int length = arr.size();
    int maxSum = INT_MIN;
    for (int start = 0; start < length; start++)
    {
        int currSum = 0;
        for (int end = 0; end < length; end++)
        {
            currSum += arr[end];
            maxSum = (maxSum < currSum) ? currSum : maxSum;
        }
    }
    return maxSum;
}

// optimized approach - kadane's algorithm - time complexity: O(n)
int kadane(vector<int> &arr)
{
    int currSum = 0, maxSum = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        currSum += arr[i];
        maxSum = max(currSum, maxSum);
        if (currSum < 0)
        {
            currSum = 0;
        }
    }
    return maxSum;
}

int main()
{
    vector<int> arr = {3, 5, 2, 6, -3, -4, 6, -8};
    cout << "Maximun sub array via brute force: " << maxSubarray(arr) << endl;
    cout << "Maximun sub array via Kadane's algorithm: " << kadane(arr) << endl;
    return 0;
}