/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.



Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.



Constraints:

    1 <= prices.length <= 105
    0 <= prices[i] <= 104


*/

#include <iostream>
#include <vector>
using namespace std;
int maxProfit(vector<int> &prices)
{
    int minPrice = __INT_MAX__; // Track the minimum price encountered so far
    int profit = 0;         // Track the maximum profit

    for (int i = 0; i < prices.size(); i++)
    {
        if (prices[i] < minPrice)
        {
            // Update the minimum price
            minPrice = prices[i];
        }
        else
        {
            // Calculate profit if sold at current price and update the max profit
            profit = max(profit, prices[i] - minPrice);
        }
    }
    return profit;
}

int main()
{
    vector<int> prices = {7,1,5,3,6,1,4};
    int profit = maxProfit(prices);
    cout << profit << endl;
    return 0;
}