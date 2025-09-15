class Solution {
public:
    bool isBroken(string word, unordered_set<char>& s) {
        for(int i=0; i<word.size(); i++) {
            if(s.find(word[i]) != s.end()) return true;
        }
        return false;
    }

    int canBeTypedWords(string text, string bl) {
        unordered_set<char> s;
        for(int i=0; i<bl.size(); i++) {
            s.insert(bl[i]);
        }

        int count = 0;
        int i = 0;
        string temp = "";
        for(int i=0; i<text.size(); i++) {
            if(text[i] == ' ') {
                if(!isBroken(temp, s)) count++;
                temp = "";
            } else {
                temp += text[i];
            }
        }

        if(!temp.empty() && !isBroken(temp, s)) count++;
        return count;
    }
};