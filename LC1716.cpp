// RESOLVE

class Solution {
public:
    int totalMoney(int n) {
        int st = 1;
        int end = 7;
        int ans = 0;
        int cnt = 0;
        while(true) {
            for(int i=st; i<=end; i++) {
                cnt++;
                ans += i;
                if(cnt == n) return ans;
            }
            st++; end++;
        }
        return ans;
    }
};