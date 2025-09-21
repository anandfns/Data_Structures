// TC : NlogN
class Solution {
public:
    int missingNumber(vector<int> &nums){
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] != i) return i;
        }

        return nums.size();
    }
};

// Hashing ~ TC : O(n)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> s;
        for(int val : nums) {
            s.insert(val);
        }

        for(int i=0; i<=nums.size(); i++) {
            if(s.find(i) == s.end()) return i;
        }

        return -1;
    }
};

// Math ~ TC : O(n)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int val : nums) {
            ans += val;
        }

        int sum = n * (n+1) / 2;
        if(sum == ans) return 0;
        else return sum - ans;
    }
};

// Binary Search ~ TC : O(logn)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int low = 0;
        int high = nums.size()-1;

        while(low <= high) {
            int mid = low + (high-low)/2;

            if(nums[mid] <= mid) low = mid+1;
            else high = mid-1;
        }

        return low;
    }
};