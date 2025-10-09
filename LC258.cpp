// Can do it recursively too instead of while(true)
// TC : O( log10(d) ) ~ Where d is the total number of digits ~ e.g.- 999999 -> sum = 54 ~ It shrinks too fast 
// Hence the number of iteration it <= 2 or 3
class Solution {
public:
    int addDigits(int num) {
        if(num/10 == 0) return num;
        while(true) {
            int sum = 0;
            while(num > 0) {
                int remain = num%10;
                sum += remain;
                num /= 10;
            }
            if(sum/10 == 0) return sum;
            num = sum;
        }
        return -1;     
    }
};

// TC : O(1)
class Solution {
public:
    int addDigits(int num) {
        if(num < 10) return num; // if num < 10 return num right away
        else if(num%9 == 0) return 9; // if num is multiple of 9 ~ then after multiple subtractions eventually it will become 9 < 10
        else return num%9; // e.g.- 38%9 -> 4 , it will always give the remainder which satisfies all conditions
    }
};