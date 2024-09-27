/*
You are given an array of strings message and an array of strings bannedWords.

An array of words is considered spam if there are at least two words in it that exactly match any word in bannedWords.

Return true if the array message is spam, and false otherwise.

 

Example 1:

Input: message = ["hello","world","leetcode"], bannedWords = ["world","hello"]

Output: true

Explanation:

The words "hello" and "world" from the message array both appear in the bannedWords array.

Example 2:

Input: message = ["hello","programming","fun"], bannedWords = ["world","programming","leetcode"]

Output: false

Explanation:

Only one word from the message array ("programming") appears in the bannedWords array.

 

Constraints:

    1 <= message.length, bannedWords.length <= 105
    1 <= message[i].length, bannedWords[i].length <= 15
    message[i] and bannedWords[i] consist only of lowercase English letters.


*/

#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_set>
using namespace std;

bool reportSpam(vector<string> &message, vector<string> &bannedWords)
{
    // Optimize input/output operations
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // Convert bannedWords into an unordered set for O(1) lookup
    unordered_set<string> bannedSet(bannedWords.begin(), bannedWords.end());

    int matchCount = 0;

    // To track distinct words found in message that match banned words
    unordered_set<string> distinctMatches;

    for (const string &word : message)
    {
        // If the word is in bannedSet and it's not already counted
        if (bannedSet.find(word) != bannedSet.end())
        {
            matchCount++;
        }

        // If we've found 2 distinct matching words, return true
        if (matchCount >= 2)
        {
            return true;
        }
    }

    // If less than 2 distinct matches, return false
    return false;
}

int main()
{
    vector<string> vec = {"l", "j", "i", "l", "i", "l"};

    vector<string> temp = {"d", "a", "i", "v", "a"};
    cout << reportSpam(vec, temp)<<endl;

    return 0;
}