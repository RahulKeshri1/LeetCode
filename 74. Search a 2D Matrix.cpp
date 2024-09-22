/*
You are given an m x n integer matrix matrix with the following two properties:

    Each row is sorted in non-decreasing order.
    The first integer of each row is greater than the last integer of the previous row.

Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.


Example 1:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Example 2:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false

 

Constraints:

    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 100
    -104 <= matrix[i][j], target <= 104
*/

#include<iostream>
#include<vector>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
    int m = matrix.size();    // Number of rows
    if (m == 0) return false; // Handle empty matrix
    int n = matrix[0].size(); // Number of columns
    if (n == 0) return false; // Handle empty rows

    int row = -1;  // Initialize row to an invalid value

    int rowup=0;
    int rowdown=m-1;
    
    // Find the row in which target could be present
    while(rowup<=rowdown) 
    {
        int mid=(rowup+rowdown)/2;
        if(matrix[mid][0] <= target && matrix[mid][n - 1] >= target)
        {
            row=mid;
            break;
        }
        else if(matrix[mid][0]>target)
        {
            rowdown=mid-1;
        }
        else
        {
            rowup=mid+1;
        }
    }

    // If no valid row was found, return false
    if (row == -1) return false;

    // Binary search on the selected row
    int left = 0;
    int right = n - 1;
    while (left <= right) 
    {
        int mid = (left + right) / 2;
        if (matrix[row][mid] == target) 
        {
            return true;
        } 
        else if (matrix[row][mid] < target) 
        {
            left = mid + 1;
        } 
        else 
        {
            right = mid - 1;
        }
    }

    return false;  // Target not found
}

int main()
{
    vector<vector<int>> matrix={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target=3;
    cout<<searchMatrix(matrix,target)<<endl;
    return 0;
}