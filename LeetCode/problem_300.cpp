// Longest Increasing Subsequence
// Given an unsorted array of integers, find the length of longest increasing subsequence.



// Solution approach #1: dynamic programming, O(n^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 0) {
            return 0;
        }
        vector<int> dp(sz, 1);
        int maxlen = 1;
        for(int i = 1; i < sz; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if(dp[i] > maxlen) {
                maxlen = dp[i];
            }
        }
        return maxlen;
    }
};

// Solution approach #2: binary search, O(nlog(n))
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 0) {
            return 0;
        }
        vector<int> res;
        vector<int>::iterator it;
        int maxlen = 1;
        res.push_back(nums[0]);
        for(int i = 1; i < sz; i++) {
            it = lower_bound(res.begin(), res.end(), nums[i]);
            // 返回res中第一个大于等于nums[i]的索引,如果全小于nums[i],返回res.end()
            if(it == res.end()) {
                res.push_back(nums[i]);
                maxlen += 1;
            } else {
                *it = nums[i];
            }
        }
        return maxlen;
    }
};
