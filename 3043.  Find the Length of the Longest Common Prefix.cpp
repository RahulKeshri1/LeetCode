#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
{
    unordered_map<string, int> Map;

    for (int i=0;i<arr1.size();i++)
    {
        string num = to_string(arr1[i]);
        string prefix = "";
        for (int j=0;j<num.size();j++)
        {
            prefix += num[j];
            Map[prefix]++;
        }
    }

    int maxLength = 0;
    for (int i=0;i<arr2.size();i++)
    {
        string num = to_string(arr2[i]);
        string prefix = "";
        for (int j=0;j<num.size();j++)
        {
            prefix += num[j];
            if (Map.find(prefix) != Map.end())
            {
                maxLength = max(maxLength, int(prefix.length()));
            }
        }
    }

    return maxLength;
}

int main()
{
    vector<int> arr1 = {1, 10, 100};
    vector<int> arr2 = {1000};
    cout << longestCommonPrefix(arr1, arr2);
    return 0;
}