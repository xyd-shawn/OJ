// Search in Rotated Sorted Array II
// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
// Write a function to determine if a given target is in the array.
// The array may contain duplicates.



// Solution approach: similar to problem 3
// 寻找最大值的方法变成了O(n)
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int sz = nums.size();
        if(sz == 0) {
            return false;
        }
        int ind_max = -1;;
        for(int i = 1; i < sz; i++) {
            if(nums[i] < nums[i - 1]) {
                ind_max = i - 1;
                break;
            }
        }
        int low, high, half;
        if(ind_max == -1) {
            low = 0;
            high = sz - 1;
        } else {
            if(target >= nums[0]) {
                low = 0;
                high = ind_max;
            } else if(target <= nums[sz - 1]) {
                low = ind_max + 1;
                high = sz - 1;
            } else {
                return false;
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
            return true;
        } else {
            return false;
        }
    }
};
