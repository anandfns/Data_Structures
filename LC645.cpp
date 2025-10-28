class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> hash;
        int n = nums.size();
        for(int i=1; i<=n; i++) {
            hash[i] = 0;
        }
        for(int i=0; i<n; i++) {
            if(hash.find(nums[i]) != hash.end()) hash[nums[i]]++;
        }

        vector<int> ans(2);
        for(auto it : hash) {
            if(it.second == 2) ans[0] = it.first;
            if(it.second == 0) ans[1] = it.first;
        }

        return ans;
    }

};