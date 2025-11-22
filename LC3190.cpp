class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt = 0;
        for(int val : nums) {
            if(val % 3 == 0) continue;
            else {
                cnt += min(val % 3, 3 - (val%3));
            }
        }
        return cnt;
    }
};