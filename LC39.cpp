class Solution {
public:
    void func(vector<int>& can, int tar, vector<vector<int>>& ans, vector<int>& temp, int idx){
        if(tar == 0) {
            ans.push_back(temp);
            return;
        }
        if(idx == can.size()) {
            if(tar == 0) {
                ans.push_back(temp);
            }
            return;
        }

        if(can[idx] <= tar) { // or if(tar > 0) 
            temp.push_back(can[idx]);
            func(can, tar - can[idx], ans, temp, idx);
            temp.pop_back();
        }

        func(can, tar, ans, temp, idx+1);
    }

    vector<vector<int>> combinationSum(vector<int>& can, int tar) {
        vector<vector<int>> ans;
        vector<int> temp;

        func(can, tar, ans, temp, 0);
        return ans;

    }
};