// Brute force - Use Linear search instead of Binary - range[1 -> n]
// Optimal ~ Binary Search ~ TC : O(N) and SC : O(1)

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        while(low <= high) {
            int mid = low + (high-low)/2;

            if(isBadVersion(mid)) high = mid - 1;
            else low = mid + 1;
        }

        return low;
    }
};