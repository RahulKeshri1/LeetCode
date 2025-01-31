/*
2610. Convert an Array Into a 2D Array With Conditions

You are given an integer array nums. You need to create a 2D array from nums satisfying the following conditions:

    The 2D array should contain only the elements of the array nums.
    Each row in the 2D array contains distinct integers.
    The number of rows in the 2D array should be minimal.

Return the resulting array. If there are multiple answers, return any of them.

Note that the 2D array can have a different number of elements on each row.

 

Example 1:

Input: nums = [1,3,4,1,2,3,1]
Output: [[1,3,4,2],[1,3],[1]]
Explanation: We can create a 2D array that contains the following rows:
- 1,3,4,2
- 1,3
- 1
All elements of nums were used, and each row of the 2D array contains distinct integers, so it is a valid answer.
It can be shown that we cannot have less than 3 rows in a valid array.

Example 2:

Input: nums = [1,2,3,4]
Output: [[4,3,2,1]]
Explanation: All elements of the array are distinct, so we can keep all of them in the first row of the 2D array.

 

Constraints:

    1 <= nums.length <= 200
    1 <= nums[i] <= nums.length


*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> findMatrix(vector<int> &nums)
{
    vector<vector<int>> ans;

    for (int i = 0; i < nums.size(); i++)
    {
        bool flag = false;
        for (int j = 0; j < ans.size(); j++)
        {
            auto it = find(ans[j].begin(), ans[j].end(), nums[i]);
            if (it == ans[j].end())
            {
                ans[j].push_back(nums[i]);
                flag = true;
                break; 
            }
        }
        if (!flag)
        {
            vector<int> temp;
            temp.push_back(nums[i]);
            ans.push_back(temp);
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 2, 3, 1, 4};
    vector<vector<int>> result = findMatrix(nums);

    // Print the result
    for (const auto &row : result)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
