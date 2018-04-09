// Subsets II
// Given a collection of integers that might contain duplicates, nums,
// return all possible subsets (the power set).
// Note: The solution set must not contain duplicate subsets.



// Solution approach #1: dfs
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int sz = nums.size();
        vector<vector<int> > res;
        vector<int> path;
        sort(nums.begin(), nums.end());
        dfs_subsetswithdup(nums, 0, path, res);
        return res;
    }
    void dfs_subsetswithdup(vector<int>& nums, int pos, vector<int>& path, vector<vector<int> >& res) {
        res.push_back(path);
        for(int i = pos; i < nums.size(); i++) {
            if(i != pos && nums[i] == nums[i - 1]) {    // 注意判断条件，尤其是第一个
                continue;
            }
            path.push_back(nums[i]);
            dfs_subsetswithdup(nums, i + 1, path, res);
            path.erase(path.end() - 1);
        }
    }
};


// Solution approach #2: 位操作+set过滤
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int sz = nums.size();
        sort(nums.begin(), nums.end());    // 一定要排序，不然会有[2,1,2]和[2,2,1]的情况
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
        set<vector<int> > filter_set;
        for(int i = 0; i < res.size(); i++) {
            filter_set.insert(res[i]);
        }
        res.clear();
        for(set<vector<int> >::iterator it = filter_set.begin(); it != filter_set.end(); it++) {
            res.push_back(*it);
        }
        return res;
    }
};
