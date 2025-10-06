// way - 1
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

// Way - 2
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        if(s.empty() && t.empty()) return false;
        
        unordered_map<char, int> map;
        for(char c : s) {
            if(map.count(c)) map[c]++;
            else map[c] = 1;
        }

        for(char c : t) {
            if(map.count(c)) map[c]--;
            if(map[c] == 0) map.erase(c);
        }

        return map.empty();
    }
};

// Way - 3 ~ Slightly Optimized by way - 2
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        if(s.empty() && t.empty()) return false;

        unordered_map<char, int> map;
        for(char c : s) map[c]++;

        for(char c : t) {
            if(map.find(c) == map.end() || map[c] == 0) return false;
            map[c]--;
        }

        return true;
    }
};