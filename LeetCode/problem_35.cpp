// Search Insert Position
// Given a sorted array and a target value, return the index if the target is found.
// If not, return the index where it would be if it were inserted in order.
// You may assume no duplicate exists in the array.



// Solution approach: binary search
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int sz = nums.size();
        if(sz == 0) {
            return 0;
        }
        int low = 0;
        int high = sz - 1;
        int half = (low + high) / 2;
        while(low < high) {
            if(nums[half] == target) {
                return half;
            } else if(nums[half] > target) {
                high = half - 1;
            } else {
                low = half + 1;
            }
            half = (low + high) / 2;
        }
        if(nums[half] < target) {
            return half + 1;
        } else {
            return half;
        }
    }
};
