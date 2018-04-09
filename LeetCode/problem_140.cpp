// Word Break II
// Given a non-empty string s and a dictionary wordDict containing a list of non-empty words,
// add spaces in s to construct a sentence where each word is a valid dictionary word.
// You may assume the dictionary does not contain duplicate words.
// Return all such possible sentences.
// For example, given s = "catsanddog", dict = ["cat", "cats", "and", "sand", "dog"].
// A solution is ["cats and dog", "cat sand dog"].



// Solution approach: dynamic programming and dfs
// 动态规划记录路径
// dfs利用路径遍历所有的可能情况
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int len = s.length();
        vector<bool> flag(len + 1, true);
        vector<int> path;
        vector<vector<int> > paths(len + 1, path);
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
                        paths[i].push_back(i - len1);
                    }
                }
            }
        }
        vector<string> res;
        if(flag[len]) {
            string back;
            dfs(paths, len, back, res, s);
        }
        return res;
    }

    void dfs(vector<vector<int> >& paths, int pos, string& back, vector<string>& res, string s) {
        if(pos == 0) {
            res.push_back(back.substr(1, back.length() - 1));
        }
        for(int i = 0; i < paths[pos].size(); i++) {
            int pre = paths[pos][i];
            back.insert(0, ' ' + s.substr(pre, pos - pre));
            dfs(paths, pre, back, res, s);
            back.erase(0, pos - pre + 1);
        }
    }
};
