// TC : O(31) ~ O(1)
class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0;
        while(n != 0) {
            if(n&1) cnt++;
            n >>= 1;
        }
        return cnt;
    }
};