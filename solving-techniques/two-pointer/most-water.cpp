#include <iostream>
#include <vector>
using namespace std;

// Container with most water - leetcode ques 11
// 2 pointer approach - time complexity = O(n)
int mostWater(vector<int> &height)
{
    int left = 0, right = height.size() - 1;
    int maxArea = 0;
    while (left < right)
    {
        int base = right - left;
        int high = min(height[left], height[right]);
        maxArea = max(maxArea, base * high);
        (height[left] < height[right]) ? left++ : right--;
    }
    return maxArea;
}

int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << mostWater(height) << endl;
    return 0;
}