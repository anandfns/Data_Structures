// TC : O(n * m)
// RESOLVE
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        
        string ans = "";
        int val = INT_MAX;
        for(int i=0; i<strs.size(); i++) {
            val = min(val, (int)strs[i].size());
        }

        for(int i=0; i<val; i++) {
            bool isAns = true;
            for(int j=0; j<strs.size()-1; j++) {
                if(strs[j][i] != strs[j+1][i]) {
                    isAns = false;
                    break;
                } 
            }
            if(isAns) ans += strs[0][i];
            else break;
        }

        return ans;
    }
};