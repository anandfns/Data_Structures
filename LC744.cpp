// Taking extra varible "ans" to store the answer
class Solution {
public:
    char nextGreatestLetter(vector<char>& let, char target) {
        int n = let.size();
        int low = 0;
        int high = n - 1;
        int ans = -1;

        while(low <= high) {
            int mid = low + (high-low)/2;

            if(let[mid] > target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if(ans != -1) return let[ans];
        return let[0];
    }
};

// Without any extra variable to store the answer
class Solution {
public:
    char nextGreatestLetter(vector<char>& let, char target) {
        int n = let.size();
        int low = 0;
        int high = n - 1;

        while(low <= high) {
            int mid = low + (high-low)/2;

            if(let[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if(low < n) return let[low];
        return let[0];
    }
};