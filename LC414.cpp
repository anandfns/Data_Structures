// TC : O(N) and SC : O(N) ~ Using set
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        int m = *max_element(nums.begin(), nums.end());
        if(s.size() < 3) return m;
        auto it = s.rbegin();
        advance(it, 2);
        return *it;
    }
};

// TC : O(N) and SC : O(1)
// cant use INT_MIN here, because one of the test case is == -2147483648 which is equal to INT_MIN
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int first = nums[0];
        int second = INT_MIN;
        int third = INT_MIN;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] == first) continue;
            if(nums[i] == second) continue;
            if(nums[i] == third) continue;
            if(nums[i] > first) {
                third = second;
                second = first;
                first = nums[i];
            } else if(nums[i] > second) {
                third = second;
                second = nums[i];
            } else if(nums[i] > third) {
                third = nums[i];
            }
        }
        if(third != INT_MIN) return third;
        else return first;
    }
};