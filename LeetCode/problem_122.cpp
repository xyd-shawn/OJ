// Best Time to Buy and Sell Stock II
// Say you have an array for which the i-th element is the price of a given stock on day i.
// Design an algorithm to find the maximum profit.
// You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times).
// However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).



// Solution approach: greedy
// 累加所有的连续递增子序列
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        int cur = 2147483647;
        int res = 0;
        for(int i = 0; i < sz; i++) {
            if(prices[i] > cur) {
                res += (prices[i] - cur);
            }
            cur = prices[i];
        }
        return res;
    }
};
