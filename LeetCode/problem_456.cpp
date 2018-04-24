// 132 Pattern
// Given a sequence of n integers a1, a2, ..., an,
// a 132 pattern is a subsequence ai, aj, ak such that i < j < k and ai < ak < aj.
// Design an algorithm that takes a list of n numbers as input and checks whether there is a 132 pattern in the list.
// Note: n will be less than 15,000.



// Solution Approach: stack
// https://leetcode.com/problems/132-pattern/discuss/94071/Single-pass-C++-O(n)-space-and-time-solution-(8-lines)-with-detailed-explanation.
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int sz = nums.size();
        int s3 = INT_MIN;
        stack<int> st;
        for(int i = sz - 1; i >= 0; i--){
            if(nums[i] < s3) {
                return true;
            }
            else {
                while(!st.empty() && nums[i] > st.top()){
                    s3 = st.top();
                    st.pop();
                }
            }
            st.push(nums[i]);
        }
        return false;
    }
};
