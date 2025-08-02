class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i = 0, j = n - 1;
        int curSum = 0;
        while(i < j){
            curSum=numbers[i] + numbers[j];
            if (curSum > target) j--;
            else if (curSum < target) i++;
            else{
                return {i + 1 , j + 1};
            }
        }
        return {};
    }
};