/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.



Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.



Constraints:

    1 <= s.length <= 2 * 10^5
    s consists only of printable ASCII characters.


*/

#include <iostream>
using namespace std;

bool isPalindrome(const std::string &s)
{
    int i = 0;
    int j = s.length() - 1;

    while (i < j)
    {
        // Move `i` to the next alphanumeric character
        while (i < j && !isalnum(s[i]))
        {
            i++;
        }

        // Move `j` to the previous alphanumeric character
        while (i < j && !isalnum(s[j]))
        {
            j--;
        }

        // Compare characters case-insensitively
        if (tolower(s[i]) != tolower(s[j]))
        {
            return false;
        }

        i++;
        j--;
    }

    return true;
}

int main()
{
    string s = "A man, a plan, a canal: Panama";
    cout << isPalindrome(s) << endl;
    return 0;
}