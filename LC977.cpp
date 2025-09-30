// Most trivial solution
// TC : O(NlogN)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++) {
            nums[i] = nums[i] * nums[i];
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};

// Optimized TC : O(N)
// But not clear, confusing
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        vector<int> ans(n,0);
        int idx = n - 1;

        while(i <= j) {
            int left = nums[i] * nums[i];
            int right = nums[j] * nums[j];

            if(left < right) {
                ans[idx--] = right;
                j--;
            }
            else if(left > right) {
                ans[idx--] = left;
                i++;
            } else {
                if(i == j) {
                    ans[idx--] = left;
                    break;
                }
                ans[idx--] = left;
                ans[idx--] = right;
                i++; j--;
            }
        }

        return ans;
    }
};

// TC : O(N)
// CLEAR and NOT CONFUSING
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        vector<int> ans(n, 0);

        for(int i=n-1; i>=0; i--) {
            if(abs(nums[low]) < abs(nums[high])) {
                ans[i] = nums[high] * nums[high];
                high--; 
            } else {
                ans[i] = nums[low] * nums[low];
                low++;
            }
        }

        return ans;
    }
};