class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int BitIdx = 0; BitIdx < 32; BitIdx++) {
            int cnt = 0;
            for(int i=0; i<nums.size(); i++) {
                if(nums[i] & (1<<BitIdx)) cnt++;
            }
            if(cnt%3 == 1) ans = ans | (1<<BitIdx);
        }
        return ans;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); i += 3) {
            if(nums[i] != nums[i-1]) return nums[i-1];
        }
        return nums[n-1];
    }
};