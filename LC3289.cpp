// #RESOLVE

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_set<int> hash;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++) {
            if(hash.find(nums[i]) == hash.end()) hash.insert(nums[i]);
            else ans.push_back(nums[i]);
            if(ans.size() == 2) return ans;
        }
        return ans;
    }
};