// Jump Game
// Given an array of non-negative integers, you are initially positioned at the first index of the array.
// Each element in the array represents your maximum jump length at that position.
// Determine if you are able to reach the last index.
// For example:
// A = [2,3,1,1,4], return true.
// A = [3,2,1,0,4], return false.



// Solution approach: greedy
// 从右往左，看能否通过当前位置达到目标位置，如果能够达到，目标位置变成当前位置，继续往左
// 最终判断0处是不是可以到达目标位置
// One form
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 1) {
            return true;
        }
        int target = sz - 1;
        int i = sz - 2;
        bool res = false;
        while(true) {
            while(i >= 0 && nums[i] == 0) {
                i--;
            }
            if(i < 0) {
                break;
            } else {
                if(i + nums[i] >= target) {    // 能否通过当前位置达到目标位置
                    if(i == 0) {
                        res = true;
                        break;
                    } else {
                        target = i;
                    }
                }
            }
            i--;
        }
        return res;
    }
};


// another form(more brief)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int sz = nums.size();
        int target = sz - 1;
        for(int i = sz - 1; i >= 0; i--) {
            if(i + nums[i] >= target) {    // 能否通过当前位置达到目标位置
                target = i;
            }
        }
        return target == 0;
    }
};
