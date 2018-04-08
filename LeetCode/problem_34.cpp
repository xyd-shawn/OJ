// Search for a Range
// Given an array of integers sorted in ascending order,
// find the starting and ending position of a given target value.
// Your algorithm's runtime complexity must be in the order of O(log n).
// If the target is not found in the array, return [-1, -1].
// For example, Given [5, 7, 7, 8, 8, 10] and target value 8, return [3, 4].



// Solution approach: 三次二分查找
// 第一次寻找target，找到的话会得到两个区间，通过第二次和第三次二分查找确定界
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int sz = nums.size();
        vector<int> res(2, -1);
        if(sz == 0) {
            return res;
        }
        int low, high, half;
        low = 0;
        high = sz - 1;
        half = low + (high - low) / 2;
        while(low < high && nums[half] != target) {
            if(nums[half] > target) {
                high = half - 1;
            } else {
                low = half + 1;
            }
            half = low + (high - low) / 2;
        }
        if(nums[half] == target) {
            low = 0;
            high = sz - 1;
            int half1 = half;
            int half2 = half;
            int left = low + (half1 - low) / 2;
            int right = half2 + (high - half2) / 2;
            while(low < half1) {
                if(nums[left] == target) {
                    half1 = left - 1;
                } else {
                    low = left + 1;
                }
                left = low + (half1 - low) / 2;
            }
            if(nums[left] != target) {
                left += 1;
            }
            while(half2 < high) {
                if(nums[right] == target) {
                    half2 = right + 1;
                } else {
                    high = right - 1;
                }
                right = half2 + (high - half2) / 2;
            }
            if(nums[right] != target) {
                right -= 1;
            }
            res[0] = left;
            res[1] = right;
        }
        return res;
    }
};
