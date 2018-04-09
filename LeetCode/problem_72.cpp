// Edit Distance
// Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2.
// (each operation is counted as 1 step.)
// You have the following 3 operations permitted on a word:
// a) Insert a character
// b) Delete a character
// c) Replace a character



// Solution approach: dynamic programming
// time: O(mn), space: O(m + n)
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        if(len1 == 0 || len2 == 0) {
            return max(len1, len2);
        }
        vector<int> pre(len2 + 1, 0);
        vector<int> cur(len2 + 1, 0);
        for(int j = 0; j <= len2; j++) {
            pre[j] = j;
        }
        for(int i = 1; i <= len1; i++) {
            cur[0] = i;
            for(int j = 1; j <= len2; j++) {
                int temp1 = pre[j - 1] + ((word1[i - 1] == word2[j - 1])? 0 : 1);
                int dist = min(pre[j], cur[j - 1]) + 1;
                cur[j] = min(dist, temp1);
            }
            for(int j = 0; j <= len2; j++) {
                pre[j] = cur[j];
            }
        }
        return cur[len2];
    }
};
