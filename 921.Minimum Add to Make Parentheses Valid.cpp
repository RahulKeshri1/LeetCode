/*
A parentheses string is valid if and only if:

    It is the empty string,
    It can be written as AB (A concatenated with B), where A and B are valid strings, or
    It can be written as (A), where A is a valid string.

You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.

    For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".

Return the minimum number of moves required to make s valid.

 

Example 1:

Input: s = "())"
Output: 1

Example 2:

Input: s = "((("
Output: 3

 

Constraints:

    1 <= s.length <= 1000
    s[i] is either '(' or ')'.
*/

#include <iostream>
#include <stack>
using namespace std;

// Method 1
int minAddToMakeValid(string s)
{
    if (s.length() == 0)
    {
        return 0;
    }
    int count = 0;
    stack<char> st;
    for (char c : s)
    {
        if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            if (st.empty())
            {
                count++;
                continue;
            }
            char top = st.top();
            st.pop();
            if (top != '(')
            {
                count++;
            }
        }
    }
    return count + st.size();
}

// Method 2
int minAddToMakeValid(string s)
{
    if (s.length() == 0)
    {
        return 0;
    }
    int open = 0;
    int close = 0;
    for (char c : s)
    {
        if (c == '(')
        {
            open++;
        }
        else if (c == ')')
        {
            if (open == 0)
            {
                close++;
            }
            else if (open > 0)
            {
                open--;
            }
        }
    }
    return open + close;
}

int main()
{
    string s = "())))((";
    cout << minAddToMakeValid(s);
    return 0;
}