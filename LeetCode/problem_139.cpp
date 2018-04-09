// Word Break
// Given a non-empty string s and a dictionary wordDict containing a list of non-empty words,
// determine if s can be segmented into a space-separated sequence of one or more dictionary words.
// You may assume the dictionary does not contain duplicate words.
// For example, given s = "leetcode", dict = ["leet", "code"].
// Return true because "leetcode" can be segmented as "leet code".



// Solution approach: dynamic programming
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.length();
        vector<bool> flag(len + 1, true);
        int sz = wordDict.size();
        for(int i = 1; i <= len; i++) {
            flag[i] = false;
            for(int j = 0; j < sz; j++) {
                int len1 = wordDict[j].length();
                if(i >= len1) {
                    int k;
                    for(k = 0; k < len1; k++) {
                        if(s[i - 1 - k] != wordDict[j][len1 - 1 - k]) {
                            break;
                        }
                    }
                    if(k == len1 && flag[i - len1]) {
                        flag[i] = true;
                        break;
                    }
                }
            }
        }
        return flag[len];
    }
};
