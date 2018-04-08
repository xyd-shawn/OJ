// Triangle
// Given a triangle, find the minimum path sum from top to bottom.
// Each step you may move to adjacent numbers on the row below.
// For example, given the following triangle
// [[2],[3,4],[6,5,7],[4,1,8,3]]
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).



// Solution approach: dynamic programming
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int sz = triangle.size();
        for(int i = 1; i < sz; i++) {
            triangle[i][0] += triangle[i - 1][0];
            triangle[i][i] += triangle[i - 1][i - 1];
            for(int j = 1; j < i; j++) {
                int left = triangle[i][j] + triangle[i - 1][j - 1];
                int right = triangle[i][j] + triangle[i - 1][j];
                triangle[i][j] = (left > right)? right: left;
            }
        }
        int res = 2147483647;
        for(int i = 0; i < sz; i++) {
            if(res > triangle[sz - 1][i]) {
                res = triangle[sz - 1][i];
            }
        }
        return res;
    }
};
