// Minimum Window Substring
// Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
// For example, S = "ADOBECODEBANC", T = "ABC"
// Minimum window is "BANC".
// If there is no such window in S that covers all characters in T, return the empty string "".
// If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.



// Solution approach: greedy
// https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems
// 用两个数分别指向子串的头尾
class Solution {
public:
    string minWindow(string s, string t) {
        int sz1 = s.size();
        int sz2 = t.size();
        if(sz1 == 0 || sz2 == 0) {
            return "";
        }
        vector<int> letter(128, 0);
        int count = sz2;
        for(int j = 0; j < sz2; j++) {
            letter[t[j]]++;
        }
        int i, j, begin, minlen;
        i = j = 0;
        minlen = INT_MAX;
        while(j < sz1) {
            if(letter[s[j]] > 0) {
                count--;
            }
            letter[s[j]]--;
            j++;
            while(count == 0) {
                if(j - i < minlen) {
                    begin = i;
                    minlen = j - i;
                }
                if(letter[s[i]] == 0) {
                    count++;
                }
                letter[s[i]]++;
                i++;
            }
        }
        if(minlen == INT_MAX) {
            return "";
        } else {
            return s.substr(begin, minlen);
        }
    }
};
