/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.



Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.



Constraints:

    3 <= nums.length <= 3000
    -105 <= nums[i] <= 105


*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;

    // Sort the input array
    sort(nums.begin(), nums.end());

    // Loop through the array
    for (int i = 0; i < nums.size() - 2; i++)
    {
        // Skip duplicates for the first element
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        // Two-pointer approach for the second and third elements
        int left = i + 1;
        int right = nums.size() - 1;

        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0)
            {
                ans.push_back({nums[i], nums[left], nums[right]});

                // Move left and right pointers and skip duplicates
                while (left < right && nums[left] == nums[left + 1])
                    left++;
                while (left < right && nums[right] == nums[right - 1])
                    right--;

                left++;
                right--;
            }
            else if (sum < 0)
            {
                // If sum is too small, move the left pointer to increase the sum
                left++;
            }
            else
            {
                // If sum is too large, move the right pointer to decrease the sum
                right--;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> vec = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = threeSum(vec);

    cout << "[";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j];
            if (j != ans[i].size() - 1)
                cout << ",";
        }
        cout << "]";
        if (i != ans.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;

    return 0;
}
