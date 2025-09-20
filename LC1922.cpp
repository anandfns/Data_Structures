// Recusrsive approah
// TC : O(n) ans SC : O(n) ~ because of recursion call stack
// This will give TLE for larger input n >= 10^5
class Solution {
public:
    long long MOD = 1e9 + 7;

    void func(long long n, int idx, long long& ans) {
        if(idx == n) return;

        if(idx%2 == 0) ans = (ans*5) % MOD;
        else ans = (ans*4) % MOD;

        func(n, idx+1, ans);
    }

    int countGoodNumbers(long long n) {
        long long ans = 1;
        func(n , 0, ans);
        return ans%MOD;
    }
};

// By using Binary Exponentiation
class Solution {
public:
    long long MOD = 1e9 + 7;
    long long power(long long n, long long x) {
        long long ans = 1;
        while(x>0) { // treating the power as a binary number
            if(x%2 == 1) {
                ans = (ans * n) % MOD;
            }
            n = (n*n)%MOD;
            x /= 2;
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        long long even = (n+1)/2; // if we use int here them it might get overflowed
        long long odd = n/2;

        long long ans = (power(5,even) * power(4,odd)) % MOD; // same here, cant use int 
        return (int)ans;
    }
};