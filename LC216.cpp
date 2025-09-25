class Solution {
public:
    void helper(vector<int>& temp, vector<vector<int>>& ans, int k, int n, int idx) {
        if(temp.size() == k) {
            if(n == 0) ans.push_back(temp);
            return;
        }

        if(n == 0) return;

        for(int i=idx; i<10; i++) {
            if(i > n) break;

            temp.push_back(i);
            helper(temp, ans, k, n-i, i+1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int>> ans;
        helper(temp, ans, k, n, 1);

        return ans;
    }
};