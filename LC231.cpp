// *********************Optimized*****************************

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n > 0 && (n & (n - 1)) == 0) { // all integers will get internally coverted into binary by the compiler and operate
                                          // - when we use bitwise operator
            return true;
        } else {
            return false;
        }
    }
};

// *****************************Using Loop**********************************

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 1) return true;
        if(n%2 != 0) return false;

        for(long int x = 1; x <= n; x = x*2) {
            if(x % n == 0) return true;
        }

        return false;
    }
};