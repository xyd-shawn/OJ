// Unique Binary Search Trees
// Given n, how many structurally unique BST's (binary search trees) that store values 1...n?



// Solution approach: 类似于卡塔兰数
class Solution {
public:
    int numTrees(int n) {
        if(n <= 2) {
            return n;
        }
        if(n == 3) {
            return 5;
        }
        vector<int> res(n + 1, 0);
        res[1] = 1;
        res[2] = 2;
        res[3] = 5;
        for(int i = 4; i <= n; i++) {
            res[i] = 2 * res[i - 1];
            for(int j = 1; j <= i - 1; j++) {
                res[i] += res[i - j] * res[j - 1];
            }
        }
        return res[n];
    }
};
