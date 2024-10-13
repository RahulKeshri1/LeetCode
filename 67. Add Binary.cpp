/*
Given two binary strings a and b, return their sum as a binary string.

 

Example 1:

Input: a = "11", b = "1"
Output: "100"

Example 2:

Input: a = "1010", b = "1011"
Output: "10101"

 

Constraints:

    1 <= a.length, b.length <= 104
    a and b consist only of '0' or '1' characters.
    Each string does not contain leading zeros except for the zero itself.


*/

#include <iostream>
#include<algorithm>
using namespace std;

string addBinary(string a, string b)
{
    string result = "";                                // To store the final binary result
    int i = a.size() - 1, j = b.size() - 1, carry = 0; // Pointers and carry

    // Loop through both strings from the last character (least significant bit)
    while (i >= 0 || j >= 0 || carry == 1)
    {
        int sum = carry;

        // Add the last digit of 'a' if it's valid
        if (i >= 0)
            sum += a[i--] - '0';

        // Add the last digit of 'b' if it's valid
        if (j >= 0)
            sum += b[j--] - '0';

        // Append the current binary digit (sum % 2)
        result += to_string(sum % 2);

        // Update carry (sum / 2)
        carry = sum / 2;
    }

    // The result is built backwards, so reverse it
    reverse(result.begin(), result.end());

    return result;
}

int main()
{
    string num1 = "111", num2 = "101";
    cout<<addBinary(num1,num2);
    cout<<endl;
    return 0;
}