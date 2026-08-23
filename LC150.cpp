class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        int n = tokens.size();

        set<string> ope = {"/", "*", "+", "-"};

        for(int i=0; i<n; i++) {
            if(ope.count(tokens[i])) {
                int a = stoi(s.top()); s.pop();
                int b = stoi(s.top()); s.pop();

                int temp;
                if(tokens[i] == "/") temp = b / a;
                if(tokens[i] == "*") temp = b * a;
                if(tokens[i] == "+") temp = b + a;
                if(tokens[i] == "-") temp = b - a;

                s.push(to_string(temp));
            }
            else s.push(tokens[i]);
        }

        return stoi(s.top());
    }
};