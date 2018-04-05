// Best Time to Buy and Sell Stock
// If you were only permitted to complete at most one transaction
// (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.



// Solution approach: greedy
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        int min = 2147483647;
        int res = 0;
        for(int i = 0; i < sz; i++) {
            if(min > prices[i]) {
                min = prices[i];
            } else {
                if(prices[i] - min > res) {
                    res = prices[i] - min;
                }
            }
        }
        return res;
    }
};
