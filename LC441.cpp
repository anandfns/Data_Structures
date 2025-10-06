// Brute Force ~ TC : O(root N) and SC : O(1)
class Solution {
public:
    int arrangeCoins(int n) {
        int ans = 0;
        long long i = 1;
        while(true) {
            long long val = i * (i+1) / 2;
            if(val <= n) {
                ans++; i++;
            }
            else break;
        }
        return ans;
    }
};

// Binary Search ~ TC : O(logN) and SC : O(1)
class Solution {
public:
    int arrangeCoins(int n) {
        // Initialize binary search boundaries
        int low = 1;
        int high = n;

        // Binary search to find the maximum full staircase
        while(low <= high) {
            // Calculate mid to prevent overflow
            long long mid = low + (high - low) / 2;

            // Total coins needed to form 'mid' complete rows
            long long coins = mid * (mid + 1) / 2;

            // If exact number of coins match, return mid
            if(coins == n) return mid;

            // If coins needed <= n, try to form more rows
            if(coins <= n) low = mid + 1;
            // If coins needed > n, reduce the number of rows
            else high = mid - 1;
        }

        // 'high' will be the largest number of full rows we can form
        return high;
    }
};
