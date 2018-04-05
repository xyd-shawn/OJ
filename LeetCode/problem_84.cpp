// Largest Rectangle in Histogram
// Given n non-negative integers representing the histogram's bar height where the width of each bar is 1,
// find the area of largest rectangle in the histogram.



// Solution approach: 分别向左向右寻找比当前值小的第一个值对应的索引
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int sz = heights.size();
        vector<int> left(sz, -1), right(sz, sz);
        stack<int> ind, hs;
        for(int i = 0; i < sz; i++) {
            while(!hs.empty() && heights[i] < hs.top()) {
                right[ind.top()] = i;
                hs.pop();
                ind.pop();
            }
            hs.push(heights[i]);
            ind.push(i);
        }
        while(!hs.empty()) {
            hs.pop();
            ind.pop();
        }
        for(int i = sz - 1; i >= 0; i--) {
            while(!hs.empty() && heights[i] < hs.top()) {
                left[ind.top()] = i;
                hs.pop();
                ind.pop();
            }
            hs.push(heights[i]);
            ind.push(i);
        }
        int res = 0;
        for(int i = 0; i < sz; i++) {
            if(res < (right[i] - left[i] - 1) * heights[i]) {
                res = (right[i] - left[i] - 1) * heights[i];
            }
        }
        return res;
    }
};
