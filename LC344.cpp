// Using in-Built Function
class Solution {
public:
    void reverseString(vector<char>& s) {
        return reverse(s.begin(), s.end());
    }
};

// BY Swapping
class Solution {
public:
    void reverseString(vector<char>& s) {
        int low = 0;
        int high = (int)s.size()-1;
        while(low < high) {
            swap(s[low++], s[high--]);
        }
    }
};