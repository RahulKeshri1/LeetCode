/*
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321

Example 2:

Input: x = -123
Output: -321

Example 3:

Input: x = 120
Output: 21

 

Constraints:

    -231 <= x <= 231 - 1
*/

#include <iostream>
using namespace std;

int reverse(int x)
{
    int ans = 0; // Initialize the reversed number to 0
    while (x != 0)
    {
        int digit = x % 10; // Get the last digit of x

        // Check for overflow/underflow before updating ans
        if ((ans > __INT32_MAX__ / 10) || (ans < (-1*__INT32_MAX__) / 10))
        {
            return 0; // Return 0 if reversing x would cause overflow/underflow
        }

        ans = ans * 10 + digit; // Append the digit to the reversed number
        x = x / 10;             // Remove the last digit from x
    }
    return ans; // Return the reversed number
}

int main()
{
    long int x = -2147483648;

    cout << reverse(x) << endl;
    return 0;
}