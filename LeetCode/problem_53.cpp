// Maximum Subarray
// Find the contiguous subarray within an array (containing at least one number) which has the largest sum.



// Solution approach 1: divide and conquer
// Solution approach 2: O(n), 最大和子串的前缀不能是负数或者和为负数的序列。



class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sz = nums.size();
        int maxnum = -2147483648;
        for(int i = 0; i < sz; i++) {
            if(nums[i] > maxnum) {
                maxnum = nums[i];
            }
        }
        if(maxnum <= 0) {
            return maxnum;
        } else {
            int maxsum = 0;
            int sum = 0;
            for(int i = 0; i < sz; i++) {
                sum += nums[i];
                if(sum < 0) {
                    sum = 0;
                } else if(sum > maxsum) {
                    maxsum = sum;
                }
            }
            return maxsum;
        }
    }
};
