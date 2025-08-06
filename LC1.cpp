class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        //Without using maps - so time complexity will be O(n2)
        for (int i = 0; i < nums.size(); i++) {
            int curSum = 0;
            for(int j = i + 1; j < nums.size(); j++) {
                curSum = nums[i] + nums[j];
                if(curSum == target) {
                    return {i,j};
                }
            }
        }

        return {-1, -1};
    }
};

//********************Using Unordered Map********************

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m; // Creating empty for - will store key ~ value of second num | value ~ its index
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int first = nums[i];
            int second = target - first;

            if(m.find(second) != m.end()) { // if the other pair w.r.t. first is found, then the indices will get returned
                return {i , m[second]};     // at first the map will be empty, so it will store the pair of fisrt
            } else { // otherwise the pair's value as key along with its index as value, get inserted into the map as a key , value pair
                m.insert({first , i});
            }
        }

        return {-1, -1};
    }
};