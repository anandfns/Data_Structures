class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int cnt = 0;
        int i = 0;
        int n = nums.size();
        while(i<n && nums[i] != 1) i++;
        for(++i; i<nums.size(); i++) {
            if(nums[i] == 1) {
                if(cnt<k) return false;
                cnt = 0;
            }
            else cnt++;
        }
        return true;
    }
};