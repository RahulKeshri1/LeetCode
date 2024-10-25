/*
You are given a 0-indexed string word, consisting of lowercase English letters. You need to select one index and remove the letter at that index from word so that the frequency of every letter present in word is equal.

Return true if it is possible to remove one letter so that the frequency of all letters in word are equal, and false otherwise.

Note:

    The frequency of a letter x is the number of times it occurs in the string.
    You must remove exactly one letter and cannot choose to do nothing.

 

Example 1:

Input: word = "abcc"
Output: true
Explanation: Select index 3 and delete it: word becomes "abc" and each character has a frequency of 1.

Example 2:

Input: word = "aazz"
Output: false
Explanation: We must delete a character, so either the frequency of "a" is 1 and the frequency of "z" is 2, or vice versa. It is impossible to make all present letters have equal frequency.

 

Constraints:

    2 <= word.length <= 100
    word consists of lowercase English letters only.

*/

#include<iostream>
#include<vector>
using namespace std;

bool equalfreq(string word)
{
    vector<int> charset(26,0);
    for(char c:word)
    {
        charset[c-'a']++;
    }
    for(int i=0;i<26;i++)
    {
        charset[i]--;
        int key=0;
        bool equal=true;
        for(int j=0;j<26;j++)
        {
            if(charset[j]==0)   continue;
            if(key==0)
            {
                key=charset[j];
                continue;
            }
            if(charset[j]!=key)
            {
                equal=false;
                break;
            }
        }
        if(equal)
        {
            return true;
        }
        charset[i]++;
    }
    
    return false;
}
int main()
{
    // string s="aabbcdde";
    string word;
    cin>>word;
    cout<<equalfreq(word)<<endl;
    return 0;
}