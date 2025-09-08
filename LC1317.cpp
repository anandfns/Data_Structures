class Solution {
public:
    bool isValid(int n) {
        while(n>0) {
            if(n%10 == 0) return false;
            n /= 10;
        }
        return true;
    }

    vector<int> getNoZeroIntegers(int n) {

        for(int i=1; i<=n; i++) {
            if(isValid(i) && isValid(n-i)) {
                return {i, n-i};
            }
        }

        return {};
    }
};