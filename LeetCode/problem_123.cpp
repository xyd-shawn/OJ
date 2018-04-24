// Best Time to Buy and Sell Stock III
// Say you have an array for which the i-th element is the price of a given stock on day i.
// Design an algorithm to find the maximum profit. You may complete at most two transactions.



// Solution approach: dynamic programming and greedy
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        if(sz == 0) {
            return 0;
        }
        vector<int> left(sz, 0);
        vector<int> right(sz, 0);
        int minleft = prices[0];
        for(int i = 1; i < sz; i++) {
            if(prices[i] > minleft) {
                left[i] = prices[i] - minleft;
            } else {
                minleft = prices[i];
            }
            left[i] = max(left[i], left[i - 1]);
        }
        int maxright = prices[sz - 1];
        for(int i = sz - 2; i >= 0; i--) {
            if(prices[i] < maxright) {
                right[i] = maxright - prices[i];
            } else {
                maxright = prices[i];
            }
            right[i] = max(right[i], right[i + 1]);
        }
        int maxsum = 0;
        for(int i = 0; i < sz; i++) {
            if(left[i] + right[i] > maxsum) {
                maxsum = left[i] + right[i];
            }
        }
        return maxsum;
    }
};
