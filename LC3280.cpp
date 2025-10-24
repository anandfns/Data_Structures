class Solution {
public:
    string helper(string s) {
        int n;
        for(int i=0; i<s.size(); i++) {
            n = n*10 + (s[i] - '0');
        }

        string binary;
        while(n != 0) {
            if(n&1) binary += '1';
            else binary += '0';
            n = n>>1;
        }
        reverse(binary.begin(), binary.end());
        return binary;
    }
    string convertDateToBinary(string date) {
        string year;
        string month;
        string day;

        for(int i=0; i<4; i++) year += date[i];
        for(int i=5; i<7; i++) month += date[i];
        for(int i=8; i<10; i++) day += date[i];

        year = helper(year);
        month = helper(month);
        day = helper(day);

        string ans = year + '-' + month + '-' + day;
        return ans;
    }
};