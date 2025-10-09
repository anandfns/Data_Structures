// Gives TLE ~ TC : O(N^2)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for(int i=1; i<=nums.size(); i++) {
            bool isThere = true;
            for(int j=0; j<nums.size(); j++) {
                if(i == nums[j]) isThere = false;
            }
        if(isThere) ans.push_back(i);
        }
        return ans;
    }
};

// TC : O(N) ans SC : O(N)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        unordered_set<int> s(nums.begin(), nums.end());
        for(int i=1; i<=nums.size(); i++) {
            if(s.find(i) == s.end()) ans.push_back(i);
        }
        return ans;
    }
};