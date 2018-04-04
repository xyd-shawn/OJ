// Longest Valid Parentheses
// Given a string containing just the characters '(' and ')',
// find the length of the longest valid (well-formed) parentheses substring.



// Solution Approach: dynamic programming
class Solution {
public:
    int longestValidParentheses(string s) {
        int sz = s.size();
        vector<int> dp;
        int res = 0;
        for(int i = 0; i < sz; i++) {
            dp.push_back(0);
            if(s[i] == ')') {
                if(s[i - 1] == '(') {
                    dp[i] = dp[i - 2] + 2;    // ends with "()"
                } else {
                    if(s[i - 1 - dp[i - 1]] == '(') {
                        dp[i] = 2 + dp[i - 1] + dp[i - 2 - dp[i - 1]];    // ends with "))"
                    }
                }
                if(dp[i] > res) {
                    res = dp[i];
                }
            }
        }
        return res;
    }
};
