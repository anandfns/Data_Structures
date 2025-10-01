// RESOLVE
// TC : O( max(a.size() , b.size()) )

class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int carry = 0;
        while(!a.empty() || !b.empty()) {
            int sum = carry;
            if(!a.empty()) sum += (a.back() - '0');
            if(!b.empty()) sum += (b.back() - '0');
            carry = 0;

            if(sum == 3) {
                carry = 1;
                ans += '1';
            } else if(sum == 2) {
                carry = 1;
                ans += '0';
            } else if(sum == 1) ans += '1';
            else ans += '0';

            if(!a.empty()) a.pop_back();
            if(!b.empty()) b.pop_back();
        }

        if(carry == 1) ans += '1';
        reverse(ans.begin(), ans.end());

        return ans;
    }
};