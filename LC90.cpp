// TC : O(2^N * N) and SC : O(N) + O(2^N * N)

// Two explicit recursive calls per element (include/exclude)
// Explicitly handles exclusion with second recursion
// Slightly longer, but more explicit for learning purposes
class Solution {
public:
    void getAllSubsets(vector<int> &nums, vector<int> &ans, int i, vector<vector<int>> &allSubsets) {
        if(i == nums.size()) {
            allSubsets.push_back(ans);
            return;
        }

        //include
        ans.push_back(nums[i]);
        getAllSubsets(nums, ans, i + 1, allSubsets);

        int idx = i + 1;
        while(idx < nums.size() && nums[idx] == nums[idx - 1]) idx++;

        ans.pop_back();
        getAllSubsets(nums, ans, idx, allSubsets);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> allSubsets;
        vector<int> ans;
        getAllSubsets(nums, ans, 0, allSubsets);
        return allSubsets;
    }
};

// Single for-loop with recursive call inside
// Implicitly handles exclusion via loop
// Shorter and more concise

class Solution {
public:
    void helper(vector<int>& nums, int idx, vector<vector<int>>& ans, vector<int>& temp) {
        ans.push_back(temp);

        for(int i=idx; i<nums.size(); i++) {
            if(i > idx && nums[i] == nums[i-1]) continue;
            temp.push_back(nums[i]);
            helper(nums, i+1, ans, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;

        helper(nums, 0, ans, temp);
        return ans;
    }
};