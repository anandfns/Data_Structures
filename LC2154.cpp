class Solution {
public:
    int findFinalValue(vector<int>& nums, int o) {
        unordered_set<int> s;
        for(int val : nums) {
            s.insert(val);
        }

        bool canWe = true;
        while(canWe) {
            if(s.find(o) != s.end()) o *= 2;
            else canWe = false;
        }

        return o;
    }
};