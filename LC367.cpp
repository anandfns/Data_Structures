class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 1;
        int high = num;
        while(low <= high) {
            int mid = low + (high-low)/2;
            long long prod = 1LL*mid*mid;

            if(prod == num) return true;
            if(prod > num) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
};