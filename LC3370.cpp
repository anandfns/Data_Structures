// #RESOLVE

class Solution {
public:
    int smallestNumber(int n) {
        bool isFound = false;
        int idx = 1;
        while(!isFound) {
            int val = pow(2,idx) - 1;
            if(val >= n) {
                return val;
                isFound = true;
            }
            idx++;
        }
        return 0;
    }
};