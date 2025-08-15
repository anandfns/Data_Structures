class Solution {
public:
    // Helper Function 
    void getAllSubsets(vector<int> &nums, vector<int>& ans, vector<vector<int>> & allSubsets, int i) {
        if(i == nums.size()) { // Base case , when we reach at the end of the recursion tree then i == nums.size()
            subs.push_back(ans);
            return;
        }

        // include
        ans.push_back(nums[i]);
        getAllSubsets(nums, ans, allSubsets, i+1);

        ans.pop_back(); // during backtracking it removes the elemet
        // exclude
        getAllSubsets(nums, ans, allSubsets, i+1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> allSubsets;
        getAllSubsets(nums, ans, allSubsets, 0);
        return subs;
    }
};