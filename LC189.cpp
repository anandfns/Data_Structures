// Easiest Solution ~ uses extra space ~ TC : O(n) ~ SC : O(n)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n; // if k > n
        
        vector<int> before;
        vector<int> after;

        for(int i=0; i<nums.size(); i++) {
            if(i < n-k) before.push_back(nums[i]);
            else after.push_back(nums[i]);
        }

        for(int i=0; i<after.size(); i++) {
            if(!after.empty()) nums[i] = after[i];
        }

        for(int i=after.size(); i<nums.size(); i++) {
            if(!before.empty()) nums[i] = before[i - after.size()];
        }
    }
};

// This will give TLE on leetcode
// in this we are rotating the array by one element k times
// TC : O(k*n) and SC : O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        while(k > 0) {
            int curr = nums[0];
            for(int i=0; i<nums.size()-1; i++) {
                int temp = nums[i+1];
                nums[i+1] = curr;
                curr = temp;
            }
            nums[0] = curr;
            k--;
        }

    }
};

// Most Optimal , TC : O(n) ans SC : O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};