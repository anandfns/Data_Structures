// Linear Search ~ Gives TLE ~ TC : O(max_elem * N)
// Binary Search ~ Accepted ~ TC : O(log(max_elem) * N)
class Solution {
public:
    typedef long long ll;
    // TC : O(N) on every call
    int possible(vector<int> can, ll k, ll maxCandy) {
        ll std = 0;
        for(ll x : can) {
            std += x/maxCandy;
            if(std >= k) return true;
        }
        return false;

        //Brute Force ~ Gives TLE for larger inputs
        // ll std = 0;
        // for(ll i=0; i<can.size(); i++) {
        //     while(can[i] >= maxCandy) {
        //         std++;
        //         if(std >= k) return true;
        //         can[i] -= maxCandy;
        //     }
        // }
        // return false;
    }
    
    int maximumCandies(vector<int>& can, long long k) {
        // Not neccessary to do this, takes extra time if we use it
        // ll sum = 0;
        // for(int x : can) sum += x;
        // if(sum < k) return 0;

        ll low = 1;
        // high == sum -> Why Not? -> because for every student we can give them candies of one type only
        // i.e. candies from same pile -> that's why we take -> high == max_elem
        ll high = *max_element(can.begin(), can.end());
        ll ans = 0;

        // Linear Search
        // for(ll i=low; i<=high; i++) {
        //     if(!possible(can, k, i)) return i - 1;
        // }

        // Binary Search
        while(low <= high) {
            ll mid = low + (high-low)/2;

            if(possible(can, k, mid)) {
                ans = mid;
                low = mid + 1;
            } else high = mid - 1;
        }
        return ans;
    }
};