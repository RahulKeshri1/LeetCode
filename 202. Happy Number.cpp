/*
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

    Starting with any positive integer, replace the number by the sum of the squares of its digits.
    Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
    Those numbers for which this process ends in 1 are happy.

Return true if n is a happy number, and false if not.

 

Example 1:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

Example 2:

Input: n = 2
Output: false

 

Constraints:

    1 <= n <= 2^31 - 1


*/

#include <iostream>
using namespace std;

bool isHappy(int n)
{
    int num = n;
    // int org=n;
    while (num > 6)
    {
        int ans = 0;
        n = num;
        while (n > 0)
        {
            int rem = n % 10;
            ans = ans + rem * rem;
            n = n / 10;
        }
        num = ans;
    }
    if (num == 1)
    {
        return true;
    }
    return false;
}

int main()
{
    int num = 1111111;
    cout << isHappy(num) << endl;
    return 0;
}