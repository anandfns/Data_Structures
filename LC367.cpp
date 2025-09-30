// A number is a perfect square if and only if it can be written as the sum of consecutive odd numbers starting from 1.
// TC : O(sqrt(num))
class Solution {
public:
    bool isPerfectSquare(int num) {
        int odd = 1;

        while(num>0){
            num = num - odd;
            odd = odd + 2;
        }
        return num==0;
    }
};

// TC : O(Log num)
class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 1;
        int high = num;
        while(low <= high) {
            int mid = low + (high-low)/2;
            long long prod = 1LL*mid*mid;

            if(prod == num) return true;
            if(prod > num) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
};

