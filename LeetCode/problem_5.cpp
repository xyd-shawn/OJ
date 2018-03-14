// Longest Palindromic Substring

// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.



// Approach #1: brute force
class Solution {
public:
    string longestPalindrome(string s) {
        int sz = s.size();
        if(sz <= 1) {
            return s;
        } else {
            int i, j, k;
            int bg = 0;
            int maxlen = 1;
            for(i = 0; i < sz; i++) {
                for(j = i + maxlen; j < sz; j++) {    // 不考虑不超过当前最长回文串长度的子串
                    bool flag = true;
                    for(k = 0; k < (j - i + 1) / 2; k++) {
                        if(s[i + k] != s[j - k]) {
                            flag = false;
                            break;
                        }
                    }
                    if(flag) {
                        if(maxlen < (j - i + 1)) {
                            bg = i;
                            maxlen = j - i + 1;
                        }
                    }
                }
            }
            string subs(s, bg, maxlen);
            return subs;
        }
    }
};



// Approach #2: dynamic programming
// time: O(n^2); space: O(n^2)
class Solution {
public:
    string longestPalindrome(string s) {
        int sz = s.size();
        if(sz <= 1) {
            return s;
        } else {
            vector<bool> subp(sz, false);
            vector<vector<bool> > p(sz, subp);
            for(int i = 0; i < sz; i++) {
                p[i][i] = true;
            }
            int maxlen = 1;
            bool flag1 = true;
            bool flag2 = false;
            for(int i = 0; i < sz - 1; i++) {
                if(s[i] == s[i + 1]) {
                    p[i][i + 1] = true;
                    flag2 = true;
                    maxlen = 2;
                }
            }
            int k = 2;
            while(flag1 || flag2) {
                bool flag = false;
                for(int i = 0; i < sz - k; i++) {
                    if(p[i + 1][i + k - 1] == true && (s[i] == s[i + k])) {    //
                        p[i][i + k] = true;
                        flag = true;
                    }
                }
                if(flag) {
                    maxlen = k + 1;
                }
                k++;
                flag1 = flag2;
                flag2 = flag;
            }
            for(int i = 0; i <= sz - maxlen; i++) {
                if(p[i][i + maxlen - 1] == true) {
                    string subs(s, i, maxlen);
                    return subs;
                }
            }
        }
    }
};



// Approach #3: center
// 利用中心对称，共有可能有(2n - 1)个中心，逐一检查即可
// time: O(n^2); space: O(1)
class Solution {
public:
    string longestPalindrome(string s) {
        int sz = s.size();
        if(sz <= 1) {
            return s;
        } else {
            int maxlen = 1;
            int bg = 0;
            for(int i = 0; i < sz; i++) {
                int k;
                for(k = 1; k < sz; k++) {
                    if(((i - k) < 0) || ((i + k) >= sz) || (s[i - k] != s[i + k])) {
                        break;
                    }
                }
                if((2 * k - 1) > maxlen) {
                    bg = i - (k - 1);
                    maxlen = 2 * k - 1;
                }
            }
            for(int i = 1; i < sz; i++) {
                int k;
                for(k = 1; k < sz; k++) {
                    if(((i - k) < 0) || ((i + k - 1) >= sz) || (s[i - k] != s[i + k - 1])) {
                        break;
                    }
                }
                if((2 * k - 2) > maxlen) {
                    bg = i - (k - 1);
                    maxlen = 2 * k - 2;
                }
            }
            string subs(s, bg, maxlen);
            return subs;
        }
    }
};
