class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size() != 2) {
            string x;
            for(int i=1; i<s.size(); i++) {
                char c = (s[i] + s[i-1]) % 10;
                x += c;
            }
            s = x;
        }
        return s[0] == s[1];
    }
};