// Subsets
// Given a set of distinct integers, nums, return all possible subsets (the power set).
// Note: The solution set must not contain duplicate subsets.



// Solution approach: 位操作
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int sz = nums.size();
        int nsets = 1 << sz;
        vector<vector<int> > res;
        for(int i = 1; i <= nsets - 1; i++) {
            vector<int> temp;
            for(int j = 0; j < sz; j++) {
                if((1 << j) & i) {
                    temp.push_back(nums[j]);
                }
            }
            res.push_back(temp);
        }
        vector<int> temp;
        res.push_back(temp);
        return res;
    }
};


// Solution approach #2: dfs
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int sz = nums.size();
        vector<vector<int> > res;
        vector<int> path;
        dfs_subsets(nums, 0, path, res);
        return res;
    }
    void dfs_subsets(vector<int>& nums, int pos, vector<int>& path, vector<vector<int> >& res) {
        res.push_back(path);
        for(int i = pos; i < nums.size(); i++) {
            path.push_back(nums[i]);
            dfs_subsets(nums, i + 1, path, res);
            path.erase(path.end() - 1);
        }
    }
};
