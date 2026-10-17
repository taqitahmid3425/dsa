#include <iostream>
#include <vector>
using namespace std;

// pair sum - 2 pointer approach - time complexity = O(n)
vector<int> pairSum(vector<int> &arr, int target)
{
    vector<int> ans;
    int i = 0, j = arr.size() - 1;
    while (i < j)
    {
        int sum = arr[i] + arr[j];
        if (sum > target)
        {
            j--;
        }
        else if (sum < target)
        {
            i++;
        }
        else
        {
            ans.push_back(arr[i]);
            ans.push_back(arr[j]);
            return ans;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {4, 8, 34, 65, 86, 90};
    int target = 73;
    vector<int> ans = pairSum(arr, target);
    cout << ans[0] << " + " << ans[1] << " = " << target << endl;
    return 0;
}