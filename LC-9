class Solution {
public:
    bool isPalindrome(int x) {
        
        if( x < 0 ) {
            return 0;
        }
         
        int num = x;
        int rev = 0;
        while(num != 0) {
            if( rev > INT_MAX/10 || rev < INT_MIN/10) { //so that rev do not get overflowed and exceed the limit of an int 
                return 0;
            }
            rev = rev * 10 + num % 10;
            num /= 10;
        }

        if( rev == x ) {
            return 1;
        }

        return 0;
    }
};