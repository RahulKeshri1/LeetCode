/*
Given an integer n, return any array containing n unique integers such that they add up to 0.



Example 1:

Input: n = 5
Output: [-7,-1,1,3,4]
Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].

Example 2:

Input: n = 3
Output: [-1,0,1]

Example 3:

Input: n = 1
Output: [0]



Constraints:

    1 <= n <= 1000
*/

#include <iostream>
#include <vector>
using namespace std;
vector<int> sumZero(int n)
{
    vector<int> ans;
    int min = -1 * (n / 2);
    while (ans.size() != n)
    {
        if (min != 0 && n % 2 == 0)
        {
            ans.push_back(min);
        }
        else if (n % 2 != 0)
        {
            ans.push_back(min);
        }
        min++;
    }
    return ans;
}
int main()
{
    int n = 5;
    vector<int> ans = sumZero(n);
    cout << '[';
    for (int i = 0; i < ans.size() - 1; i++)
    {
        cout << ans[i] << ",";
    }
    cout << ans[ans.size() - 1] << ']' << endl;
    return 0;
}