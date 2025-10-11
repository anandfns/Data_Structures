class Solution {
public:
    bool checkZeroOnes(string s) {
        if(s.size() == 1) {
            if(s[0] == '1') return true;
            else return false;
        }

        int zero = 0;
        int one = 0;
        int maxZero = 0;
        int maxOne = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '1') {
                one++;
                zero = 0;
                maxOne = max(one, maxOne);
            } else {
                zero++;
                one = 0;
                maxZero = max(zero, maxZero);
            }
        }
        return maxOne>maxZero;
    }
};