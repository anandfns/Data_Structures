// resolve
class Solution {
public:
    int longestBalanced(string s) {
        string ans = "";
        int n = s.size();
        for(int i=0; i<n; i++) {
            unordered_map<char, int> map;
            string curr = "";
            for(int j=i; j<n; j++) {
                map[s[j]]++;
                curr += s[j];

                int val = map.begin()->second;
                bool isBalanced = true;
                for(auto& it : map) {
                    if(it.second != val) {
                        isBalanced = false;
                        break;
                    }
                }
                if(isBalanced && ans.size() < curr.size()) ans = curr;
            }
        }
        return ans.size();
    }
};