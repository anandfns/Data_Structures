class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> s;
        for(int val : allowed) s.insert(val);

        int ans = 0;
        for(int i=0; i<words.size(); i++) {
            string x = words[i];
            bool isTrue = true;
            for(int j=0; j<x.size(); j++) {
                if(s.find(x[j]) == s.end()) isTrue = false;
            }

            if(isTrue) ans++;
        }

        return ans;
    }
};