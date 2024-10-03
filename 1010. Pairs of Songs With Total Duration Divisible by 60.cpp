/*
You are given a list of songs where the ith song has a duration of time[i] seconds.

Return the number of pairs of songs for which their total duration in seconds is divisible by 60. Formally, we want the number of indices i, j such that i < j with (time[i] + time[j]) % 60 == 0.



Example 1:

Input: time = [30,20,150,100,40]
Output: 3
Explanation: Three pairs have a total duration divisible by 60:
(time[0] = 30, time[2] = 150): total duration 180
(time[1] = 20, time[3] = 100): total duration 120
(time[1] = 20, time[4] = 40): total duration 60

Example 2:

Input: time = [60,60,60]
Output: 3
Explanation: All three pairs have a total duration of 120, which is divisible by 60.



Constraints:

    1 <= time.length <= 6 * 10^4
    1 <= time[i] <= 500


*/

#include <iostream>
#include <vector>
using namespace std;

int numPairsDivisibleBy60(vector<int> &time)
{
    vector<int> remainder(60, 0); // To store the count of remainders
    int count = 0;

    for (int t : time)
    {
        int rem = t % 60; // Get the remainder

        // If remainder is 0, we need another element with remainder 0
        if (rem == 0)
        {
            count += remainder[0];
        }
        else
        {
            // Otherwise, we need an element with remainder (60 - rem)
            count += remainder[60 - rem];
        }

        // Update the remainder count
        remainder[rem]++;
    }

    return count;
}

int main()
{
    vector<int> time = {30, 20, 150, 100, 40};
    cout << numPairsDivisibleBy60(time) << endl;
    return 0;
}