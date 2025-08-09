// **********************************************
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;

        for(long int x = 1; x<=n; x=x*3) {
            if(x % n == 0) return true;
        }

        return false;
    }
};

// ******************* Chat GPT ***************************
class Solution {
    public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        while (n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }
};

// ********************** Fastest Way | Mathematical Approach ************************

class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0; // 3^19 = 1162261467 is max power of 3 in 32-bit
    }
};
