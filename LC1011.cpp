// Brute Force is Simple too ~ use Linear Search instead of Binary search from [1 -> total sum of weights]
// Optimal ~ Using Binary Search ~ TC : O(N * Log(Sum(W)))
class Solution {
public:
    // CRUX
    bool check(vector<int>& w, int days, int mid) {
        int sum = 0;
        int totalDays = 1;

        for(int i=0; i<w.size(); i++) {
            sum += w[i];
            if(sum > mid) {
                totalDays += 1;
                sum = w[i];
            }
        }
        return totalDays <= days;
    }
    
    int shipWithinDays(vector<int>& w, int days) {
        int low = *max_element(w.begin(), w.end());
        int high = 0;
        for(int i=0; i<w.size(); i++) high += w[i];
        // int ans = high;
        
        while(low <= high) {
            int mid = low + (high-low)/2;

            if(check(w, days, mid)) {
                // ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};