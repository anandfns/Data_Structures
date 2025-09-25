class Solution {
public:
    void helper(string dig, string temp, vector<string>& ans, int idx, map<char, vector<char>>& m) {
        if(idx == dig.size()) {
            ans.push_back(temp);
            return;
        }

        vector<char> vec = m[dig[idx]];
        for(int i=0; i <vec.size() ; i++) {
            temp.push_back(vec[i]);
            helper(dig, temp, ans, idx+1, m);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        map<char, vector<char>> m = {
            {'2', {'a', 'b', 'c'}},
            {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}},
            {'9', {'w', 'x', 'y', 'z'}}
        };
        vector<string> ans;
        string temp = "";
        
        helper(digits, temp, ans, 0, m);
        return ans;
    }
};