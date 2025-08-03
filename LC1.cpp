class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        //Without using maps - so time complexity will be O(n2)
        for (int i = 0; i < nums.size(); i++) {
            int curSum = 0;
            for(int j = i + 1; j < nums.size(); j++) {
                curSum = nums[i] + nums[j];
                if(curSum == target) {
                    return {i,j};
                }
            }
        }

        return {-1, -1};
    }
};