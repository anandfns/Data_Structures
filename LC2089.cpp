// Linear Search ~ Good for small arrays
// TC : O(NLogN) ~ Because to sort()
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == target) ans.push_back(i);
        }
        return ans;
    }
};

// Binary search ~ Good for large size arrays
// TC : O(NLogN) ~ Since we have to sort the array first that's why, otherwise it would have been O(logN)
class Solution {
public:
    int upperIDX(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;

        while(low <= high) {
            int mid = low + (high-low)/2;

            if(nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }

        return high;
    }

    int lowerIDX(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;

        while(low <= high) {
            int mid = low + (high-low)/2;

            if(nums[mid] >= target) high = mid - 1;
            else low = mid + 1;
        }

        if(low < nums.size() && nums[low] == target) return low;
        return -1;
    }

    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        if(lowerIDX(nums, target) == -1) return ans;
        int st = lowerIDX(nums, target);
        int end = upperIDX(nums, target);
        for(int i=st; i<=end; i++) {
            ans.push_back(i);
        }
        return ans;
    }
};