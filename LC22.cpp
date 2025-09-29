class Solution {
public:
    void helper(int n, int open, int close, string temp, vector<string>& ans) {
        // base case
        if(open == close && open + close == 2 * n) {
            ans.push_back(temp);
            return;
        }

        if(open < n) {
            temp.push_back('(');
            helper(n, open+1, close, temp, ans);
            temp.pop_back();
        }

        if(close < open) {
            temp.push_back(')');
            helper(n, open, close+1, temp, ans);
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(n, 0, 0, "", ans);
        return ans;
    }
};