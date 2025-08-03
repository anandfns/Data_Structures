//Brute Force
vector<int> product(vector<int> & nums) {
    int n = nums.size();
    vector<int> ans(n,0);

    for(int i=0; i<n; i++) {
        int p = 1;
        for(int j=0; j<n; j++) {
            if(i != j) {
                p *= nums[j];
            }
        }
        ans[i] = p;  
    }

    return ans;
}

//Optimal O(3n) = O(n) but space complexity is not O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);

        vector<int> prefix(n,1); //for storing the product of all values to the left of an index
        vector<int> suffix(n,1); //for storing the product of all values to the right of an index
        
        //prefix array
        for(int i = 1; i < n; i++) { // i=1 because if we take i=0, then i-1 will cause the boundary error for an array | we will take 1st 
            prefix[i] = prefix[i-1] * nums[i-1]; //element as 1 always because we are assuming that the prefix of first element is 1
        }

        //suffix array
        for(int i = n - 2; i >= 0; i--) { //i=n-2 i=1 because if we take i=n-1, then i+1 will cause the boundary error for an array | we will 
            suffix[i] = suffix[i+1] * nums[i+1]; //take last element as 1 always because we are assuming that the suffix of last element is 1
        }

        //answer array
        for(int i = 0; i < n; i++) {
            ans[i] = prefix[i] * suffix[i];
        }

        return ans;
    }
};

//Optimal TC : O(n) and SC : O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);

        
        for(int i = 1; i < n; i++) {
            ans[i] = ans[i-1] * nums[i-1];
        }
        
        int suffix = 1; // we need this because in answer array prefix is already got stored in previous loop
        for(int i = n - 2; i >= 0; i--) {
            suffix = suffix * nums[i+1];
            ans[i] = ans[i] * suffix;
        }

        return ans;
    }
};