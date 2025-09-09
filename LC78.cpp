class Solution {
public:
    void func(vector<int>& nums, int idx, vector<int>& temp, vector<vector<int>>& ans) {
        if(idx >= nums.size()) {
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]);
        func(nums, idx+1, temp, ans);

        temp.pop_back(); // works during backtracking
        func(nums, idx+1, temp, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        func(nums, 0, temp, ans); // 0 is the initial idx of nums
        return ans;
    }
};