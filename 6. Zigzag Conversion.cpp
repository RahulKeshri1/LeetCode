/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);

 

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I

Example 3:

Input: s = "A", numRows = 1
Output: "A"

 

Constraints:

    1 <= s.length <= 1000
    s consists of English letters (lower-case and upper-case), ',' and '.'.
    1 <= numRows <= 1000
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string convert(string s, int numRows)
{
    // Handle edge cases
    if (numRows == 1 || numRows >= s.length())
    {
        return s;
    }

    vector<vector<char>> ans(numRows); // Use vector of vector of char
    int idx = 0;                       // Index for the input string
    int n = s.length();

    while (idx < n)
    {
        // Traverse downwards
        for (int i = 0; i < numRows && idx < n; i++)
        {
            ans[i].push_back(s[idx++]);
        }
        // Traverse upwards
        for (int i = numRows - 2; i > 0 && idx < n; i--)
        {
            ans[i].push_back(s[idx++]);
        }
    }

    // Build the result string
    string result;
    for (const auto &row : ans)
    {
        result.append(row.begin(), row.end()); // More efficient than concatenating in a loop
    }

    return result;
}

int main()
{
    string s = "PAYPALISHIRING";
    int numRows = 3;
    cout << convert(s, numRows) << endl; // Outputs "PAHNAPLSIIGYIR"
    return 0;
}
