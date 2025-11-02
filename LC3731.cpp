// #RESOLVE
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        unordered_set<int> s(nums.begin(), nums.end());
        for(int j=nums[0]; j<=nums.back(); j++) {
            if(s.find(j) == s.end()) {
                ans.push_back(j);
            }
            s.insert(j);
        }
        return ans;
    }
};