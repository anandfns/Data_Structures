class Solution {
public:
    void helper(vector<int>& nums, int target, int idx, vector<int>& temp, vector<vector<int>>& ans) {
        if(target == 0) {
            ans.push_back(temp);
            return;
        }

        if(idx == nums.size()) {
            if(target == 0) ans.push_back(temp);
            return;
        }

        for(int i=idx; i<nums.size(); i++) {
            if(i > idx && nums[i] == nums[i-1]) continue;
            if(nums[i] > target) break;
            temp.push_back(nums[i]);
            helper(nums, target-nums[i], i+1, temp, ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& can, int target) {
        sort(can.begin(), can.end());

        vector<int> temp;
        vector<vector<int>> ans;
        helper(can, target, 0, temp, ans);
        return ans;
    }
};