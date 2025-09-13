// TC : O(n) and SC : O(26(max) = constant)
class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    int maxFreqSum(string s) {
        unordered_map<char, int> m;

        int maxVow = 0;
        int maxCon = 0;

        for(char ch : s) {
            if(m.find(ch) == m.end()) {
                m[ch] = 0;
            }
            m[ch]++;
        }

        for(auto it = m.begin(); it != m.end(); it++) {
            if(isVowel(it->first)) {
                maxVow = max(maxVow, it->second);
            } else {
                maxCon = max(maxCon, it->second);
            }
        }

        return maxVow + maxCon;
    }
};