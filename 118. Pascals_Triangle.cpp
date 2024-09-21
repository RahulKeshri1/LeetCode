/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

             1
            1 1
           1 2 1
          1 3 3 1
         1 4 6 4 1


Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:

Input: numRows = 1
Output: [[1]]



Constraints:

    1 <= numRows <= 30


*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans;
    vector<int> temp;
    if (numRows < 2)
    {
        // cout << "If block is running" << endl;
        temp.push_back(1);
        ans.push_back(temp);
        return ans;
    }
    else if (numRows >= 2)
    {
        // cout << "Else if block is running" << endl;
        temp.push_back(1);
        ans.push_back(temp);
        temp.clear();
        temp.push_back(1);
        temp.push_back(1);
        ans.push_back(temp);
        temp.clear();
        // return ans;
    }
    for (int i = 3; i <= numRows; i++) // Row Number
    {
        // cout << "For loop is running  at i= " << i << endl;
        temp.push_back(1);
        for (int j = 1; j <=(i - 2); j++) // Element
        {
            // cout << "Internal For loop is running  at j= " << j << endl;
            // cout<<"ans[i - 2][j]= "<<ans[i - 2][j-1]<<"            "<<" ans[i - 2][j]= "<<ans[i - 2][j]<<" and element = "<<ans[i -2][j-1]+ans[i - 2][j]<<endl;
            int element = ans[i - 2][j-1] + ans[i - 2][j ];
            temp.push_back(element);
        }
        temp.push_back(1);
        ans.push_back(temp);
        temp.clear();
    }
    return ans;
}

int main()
{
    int numRows;
    cout << "Enter the No. of Rows:\t";
    cin >> numRows;
    vector<vector<int>> ans;
    ans = generate(numRows);
    cout << "[";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "]";
    }
    cout << "]";
    return 0;
}