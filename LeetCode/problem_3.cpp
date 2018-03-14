// Longest Substring Without Repeating Characters

// Given a string, find the length of the longest substring without repeating characters.
// Examples:
// Given "abcabcbb", the answer is "abc", which the length is 3.
// Given "bbbbb", the answer is "b", with the length of 1.
// Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int sz = s.size();
        if(sz == 0) {
            return 0;
        } else {
            int maxlen, curlen, begin, next, j, k;
            maxlen = curlen = 1;
            begin = next = j = k = 0;
            while((begin + curlen) < sz) {
                for(j = next + 1; j < sz; j++) {
                    for(k = j - 1; k >= begin; k--) {
                        if(s[j] == s[k]) {
                            break;
                        }
                    }
                    if(k < begin) {
                        curlen += 1;
                    } else {
                        begin = k + 1;
                        next = j;
                        if(curlen > maxlen) {
                            maxlen = curlen;
                        }
                        curlen = j - k;
                        break;
                    }
                }
            }
            if(curlen > maxlen) {
                maxlen = curlen;
            }
            return maxlen;
        }
    }
};
