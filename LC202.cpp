// TC : O(LogN)
//RESOLVE
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<long long> s;
        long long num = n;
        long long sum = 0;
        while(true) {
            sum = 0;
            while(num != 0) {
                int rem = num%10;
                sum += rem * rem;

                num /= 10;
            }

            if(sum == 1) return true;

            num = sum;
            if(s.find(sum) == s.end()) {
                s.insert(sum);
            } else break;
        }
        return false;
    }
};