// resolve
// Backtracking + Hash Map ~ TC : O(n!) ~ SC : O(N)
class Solution {
public:
    void helper(vector<int>&nums, vector<int>& temp, unordered_map<int, int>& map, vector<vector<int>>& ans) {
        if(temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for(auto &it : map) {
            if(map[it.first] > 0) {
                temp.push_back(it.first);
                map[it.first]--;
                helper(nums, temp, map, ans);
                map[it.first]++;
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int val : nums) map[val]++;

        vector<vector<int>> ans;
        vector<int> temp;
        helper(nums, temp, map, ans);
        return ans;
    }
};