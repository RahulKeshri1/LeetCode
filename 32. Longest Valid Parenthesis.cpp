/*
Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses
substring
.

 

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".

Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".

Example 3:

Input: s = ""
Output: 0

 

Constraints:

    0 <= s.length <= 3 * 104
    s[i] is '(', or ')'.
*/

#include <iostream>
#include <stack>
using namespace std;

int longestValidParentheses(string s)
{
    stack<int> st;
    st.push(-1); // Initialize with -1 to handle edge cases where valid substring starts at index 0
    int maxLength = 0;

    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '(')
        {
            // Push the index of the opening parenthesis
            st.push(i);
        }
        else
        {
            // For a closing parenthesis
            st.pop();
            if (st.empty())
            {
                // If the stack is empty, push the current index as the base for the next valid substring
                st.push(i);
            }
            else
            {
                // Calculate the length of the valid substring
                maxLength = max(maxLength, i - st.top());
            }
        }
    }

    return maxLength;
}

int main()
{
    string s = "(()";
    cout<<longestValidParentheses(s)<<endl;
    return 0;
}