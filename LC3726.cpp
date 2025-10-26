class Solution {
public:
    long long removeZeros(long long n) {
        long long ans = 0;
        while(n != 0) {
            int rem = n%10;
            if(rem != 0) ans = ans*10 + rem;
            n /= 10;
        }

        long long x = 0;
        while(ans != 0) {
            int rem = ans%10;
            x = x*10 + rem;
            ans /= 10;
        }

        return x;
    }
};