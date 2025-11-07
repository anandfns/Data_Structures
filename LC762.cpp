class Solution {
public:
    bool check(int n) {
        if(n < 2) return false;
        for(int i=2; i*i <= n; i++) {
            if(n % i == 0) return false;
        }
        return true;
    }

    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for(int i=left; i<=right; i++) {
            int val = i;
            int cnt = 0;
            while(val != 0) {
                if(val&1) cnt++;
                val = val>>1;
            }

            if(check(cnt)) ans++;
        }

        return ans;
    }
};