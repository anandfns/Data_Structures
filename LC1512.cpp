// TC : O(n*(n-1)) ~ O(N^2)
// SC : O(1)
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                if(nums[i] == nums[j]) cnt++;
            }
        }
        return cnt;
    }
};

// TC : O(N)
// SC : O(N)
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        unordered_map<int, int> map;
        for(int i=0; i<n; i++) {
            map[nums[i]]++;
        }
        for(auto it : map) {
            int s = it.second;
            cnt = cnt + s*(s-1)/2;
        }
        return cnt;
    }
};

// Same as above everything intact , but is a compact format
// TC : O(N)
// SC : O(N)
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        unordered_map<int, int> map;
        for(int val : nums) {
            // cnt = cnt + map[val];
            // map[val]++;
            cnt += map[val]++;
        }
        return cnt;
    }
};