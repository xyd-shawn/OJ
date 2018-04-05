// Jump Game II
// Given an array of non-negative integers, you are initially positioned at the first index of the array.
// Each element in the array represents your maximum jump length at that position.
// Your goal is to reach the last index in the minimum number of jumps.



// Solution approach: greedy
// https://www.tianmaying.com/tutorial/LC45
class Solution {
public:
    int jump(vector<int>& nums) {
        int sz = nums.size();
        vector<int> left, right;    // left[i], right[i]记录steps=i的输入数组索引的范围
        left.push_back(0);
        right.push_back(0);
        int ind = 0;
        while(right[ind] < sz - 1) {
            left.push_back(right[ind] + 1);
            int temp = -1;
            for(int i = left[ind]; i <= right[ind]; i++) {
                if(i + nums[i] >= temp) {
                    temp = i + nums[i];
                }
            }
            right.push_back(temp);
            ind++;
        }
        return ind;
    }
};
