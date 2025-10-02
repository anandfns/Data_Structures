class Solution {
public:
    int lengthOfLastWord(string s) {
        int end = (int)s.size()-1;
        int ans = 0;
        // skipping till first non-space char from end
        while(end>=0 && s[end] == ' ') end--;

        // count the len of last word
        while(end>=0 && s[end] != ' ') {
            ans++; end--;
        }

        return ans;
    }
};