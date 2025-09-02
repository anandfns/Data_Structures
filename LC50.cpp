class Solution {
public:
    double myPow(double x, int n) {

        if(x == 0) return 0;
        if(n == 0) return 1;
        if(x == 0 && n == 0) return -1; // Mathematically undefined 

        long int binaryForm = n; // to handle overflow condition

        if(n < 0) { // for negative powers
            x = 1 / x;
            binaryForm = -binaryForm;
        }

        double ans = 1;

        while(binaryForm > 0) { //logic
            if(binaryForm % 2 != 0) {
                ans *= x;
            }
            x *= x;
            binaryForm /= 2;
        }

        return ans;
    }
};

// By Recursion
class Solution {
public:
    double f(double x, long long n, double ans) {
        // base case
        if(n == 0) return ans;

        if(n%2 != 0) {
            ans = ans * x;
        }

        return f(x*x, n/2, ans);
    }
    double myPow(double x, int n) {

        if(x == 0 && n == 0) return -1;
        if(n == 0 || x == 1) return 1;
        if(x == 0) return 0;
        
        long long binaryForm = n;
        if(n < 0) {
            x = 1 / x;
            binaryForm = -binaryForm;
        }

        double ans = f(x, binaryForm, 1);
        return ans;
    }
};