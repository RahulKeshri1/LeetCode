/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.


Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:

Input: nums = [], target = 0
Output: [-1,-1]

 

Constraints:

    0 <= nums.length <= 105
    -109 <= nums[i] <= 109
    nums is a non-decreasing array.
    -109 <= target <= 109


*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> searchRange(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    vector<int> ans(2, -1);
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] == target)
        {
            ans[0] = mid;
            ans[1] = mid;
            break;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    if (ans[0] == -1)
    {
        return ans;
    }
    int i = ans[0];
    while (i >= 0)
    {
        if (nums[i] == target)
        {
            ans[0] = i;
        }
        else
        {
            break;
        }
        i--;
    }
    i = ans[1];
    while (i < nums.size())
    {
        if (nums[i] == target)
        {
            ans[1] = i;
        }
        else
        {
            break;
        }
        i++;
    }
    return ans;
}

int main()
{
    vector<int> vec = {5,7,7,8,8,10};
    int target=8;
    vector<int> range=searchRange(vec,target);
    cout<<"["<<range[0]<<","<<range[1]<<"]"<<endl;
    return 0;
}