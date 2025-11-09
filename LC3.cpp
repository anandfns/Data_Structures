// Brute Force
// TC : O(n^2) 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        for(int i=0; i<s.size(); i++) {
            unordered_set<char> hash;
            int cnt = 0;
            for(int j=i; j<s.size(); j++) {
                if(hash.find(s[j]) != hash.end()) break;
                else hash.insert(s[j]);
                cnt++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};