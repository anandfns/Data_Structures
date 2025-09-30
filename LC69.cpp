// Basic Approach TC : O(root N)
class Solution {
public:
    int mySqrt(int x) {
        int ans = 1;
        for(long long i=0; i<=x; i++) {
            if(i*i <= x) ans = i;
            else break;
        }

        return ans;
    }
};

// Binary Search TC: O(logN)
class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;
        while(low <= high) {
            // long long so that val do not get overflowed
            long long mid = low + (high-low)/2;
            long long val = mid * mid;

            if(val > x) high = mid - 1;
            else low = mid + 1;
        }

        return high;
    }
};