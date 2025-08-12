// ************************* Brute Force ****************************

class Solution { // TC : O(n) and SC : O(n)
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> m;
        unordered_set<int> s;
        
        vector<int> ans;
        int freq = n / 3;

        for(int i=0; i<n; i++) {
            if(m.find(nums[i]) == m.end()) {
                m[nums[i]] = 0;
            }
            m[nums[i]]++;

            if(m[nums[i]] > freq) {
                if(s.find(nums[i]) == s.end()) {
                    s.insert(nums[i]);
                    ans.push_back(nums[i]);
                }
            }
        }

        return ans;
    }
};