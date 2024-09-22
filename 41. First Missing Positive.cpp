/*
Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.


Example 1:

Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.

Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.

Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.

 

Constraints:

    1 <= nums.length <= 105
    -231 <= nums[i] <= 231 - 1


*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int firstMissingPositive(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int counter = 1;
    int index = nums.size(); // Initialize index with an invalid position

    // To find the index of the first positive element in nums
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
        {
            index = i;
            break;
        }
    }

    // If no positive element found, return 1
    if (index == nums.size())
        return 1;

    // Now find the first missing positive number
    for (int i = index; i < nums.size(); i++)
    {
        if (i > index && nums[i] == nums[i - 1])
            continue; // Skip duplicates

        if (nums[i] != counter)
        {
            return counter;
        }
        counter++;
    }

    return counter;
}

int main()
{
    vector<int> vec = {7, 8, 9, 11, 12};
    int ans = firstMissingPositive(vec);
    cout << ans << endl;
    return 0;
}