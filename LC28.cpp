class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i=0; i<haystack.size(); i++) {
            if(haystack[i] == needle[0]) {
                bool isAns = true;
                for(int j=0; j<needle.size(); j++) {
                    if(j+i < haystack.size() && haystack[j+i] == needle[j]) continue;
                    else isAns = false;
                }
                if(isAns) return i;
            }
        }
        return -1;
    }
};