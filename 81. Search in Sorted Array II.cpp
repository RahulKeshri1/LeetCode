#include <iostream>
#include <vector>
using namespace std;

bool search(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] == target)
        {
            return true;
        }

        // If nums[low] == nums[mid], we can't determine the sorted half, so increment low
        if (nums[low] == nums[mid])
        {
            low++;
        }
        else if (nums[low] <= nums[mid])
        {
            // Left half is sorted
            if (nums[low] <= target && target < nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            // Right half is sorted
            if (nums[mid] < target && target <= nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return false;
}

int main()
{
    vector<int> nums = {5, 6, 7, 8, 9, 0, 1, 2};
    int x = 5;
    cout << search(nums, x);
    return 0;
}