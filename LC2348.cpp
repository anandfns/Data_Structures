class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long count = 0;
        long long freq = 0;
        
        for(int i=0; i<n; i++) {
            if(nums[i] == 0) freq++;
            else {
                count += freq * (freq + 1) / 2;
                freq = 0;
            }
        }
        
        // if last element is zero then the above for loop will not add the remaining number of subarrays of last consecutive zeros
        if(nums[n - 1] == 0) {
            count += freq * (freq + 1) / 2;
        }

        return count;

    }
};