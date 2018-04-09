// Search in Rotated Sorted Array
// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
// You are given a target value to search. If found in the array return its index, otherwise return -1.
// You may assume no duplicate exists in the array.



// Solution approach: binary search
// 第一次找最大元，以此元素将序列分成两段(可能只有一段)，然后在其中一段二分查找
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int sz = nums.size();
        if(sz == 0) {
            return -1;
        }
        int low = 0;
        int high = sz - 1;
        int half = (low + high) / 2;
        while(low < high) {
            if(half == (sz - 1)) {
                if(nums[half] > nums[0]) {
                    break;
                } else {
                    high = half - 1;
                }
            } else {
                if(nums[half] >= nums[0] && nums[half + 1] < nums[0]) {
                    break;
                } else if(nums[half] < nums[0]) {
                    high = half - 1;
                } else {
                    low = half + 1;
                }
            }
            half = (low + high) / 2;
        }
        if(half == (sz - 1)) {
            low = 0;
            high = sz - 1;
        } else {
            if(target >= nums[0]) {
                low = 0;
                high = half;
            } else if(target <= nums[sz - 1]) {
                low = half + 1;
                high = sz - 1;
            } else {
                return -1;
            }
        }
        half = (low + high) / 2;
        while(low < high) {
            if(nums[half] == target) {
                break;
            } else if(nums[half] < target) {
                low = half + 1;
            } else {
                high = half - 1;
            }
            half = (low + high) / 2;
        }
        if(nums[half] == target) {
            return half;
        } else {
            return -1;
        }
    }
};
