// **************************Nested Loops****************************

class Solution { // TC : O(n2) and SC : O(1)
public:
    int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    int ans = 0;

    for(int i=0; i<n; i++) {
        int sum = 0;
        for(int j=i; j<n; j++) {
            sum += nums[j];
            if(sum == k) ans++;
        }
    }

    return ans;
        
    }
};

// **********************Prefix sum + Hashing*************************

class Solution { // TC : O(n) and SC : O(n)
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixSum(n, 0); //To create a vector in which we store the prefix sum w.r.t. all the elemets to avoid nested loops
        int count = 0;

        prefixSum[0] = nums[0];
        for(int i=1; i<n; i++) {
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }

        unordered_map<int, int> m;
        for(int j=0; j<n; j++) {
            if(prefixSum[j] == k) count++; // if value of prefix sum == 0 , it means there is a subArr which is starting from idx = 0
                                           // and have sum == k, so we directly add it to the answer

            int val = prefixSum[j] - k;  // prefixSum[i - 1] + prefixSum[j] = k || we are assuming val == prefixSum[i - 1];
            if(m.find(val) != m.end()) { // agar val map me mila (for 1st iteration obviously there is nothing in that map) to count me 
                                         // uske frequency ko add kar denge ( because : frequency = number of subarray having sum = )
                count += m[val];
            }

            if(m.find(prefixSum[j]) == m.end()) {
                m[prefixSum[j]] = 0;
            }
            m[prefixSum[j]]++;
        }

        return count;
    }
};    