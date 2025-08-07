//**********************Brute Force****************************

vector<vector<int>> sum3(vector<int> arr){
    int n = arr.size();
    set<vector<int>> s; // To check if the triplet is repeating or not , because we need unique triplets
    vector<vector<int>> ans; // we will store all the triplet in this 2D vector
    for(int i = 0; i < n - 2; i++) {
        for(int j = i + 1; j < n - 1; j++) {
            for(int k = j + 1; k < n; k++) {
                if(arr[i] + arr[j] + arr[k] == 0) {
                    vector<int> unsorted = {arr[i] , arr[j], arr[k]}; // Storing the triplets in a temporary 1D vector, w'll use it as a row
                    sort(unsorted.begin(), unsorted.end());           // Sorting the array before storing it in a set, to get unique triplets
                    if(s.find(unsorted) == s.end()) {
                        ans.push_back(unsorted);
                    }

                    s.insert(unsorted);
                }
            }
        }
    }

    return ans;
}

// *************************Optimal*********************************

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> sv;

        // a + b + c = 0
        // b + c = -a = target
        // c = target - b

        for(int i = 0; i < n; i++) {
            set<int> s;
            int a = nums[i];
            int target = -a;
            for(int j = i + 1; j < n; j++) {
                int b = nums[j];
                int c = target - b;
                if(s.find(c) != s.end()) {
                    vector<int> trip = {a , b, c};
                    sort(trip.begin(), trip.end());
                    sv.insert(trip);
                }

                s.insert(b);
            }
        }

        vector<vector<int>> ans(sv.begin(), sv.end());

        return ans;
    }
};

// *****************Optimized Approach ( Two Pointer Approach )**********************

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue; // if the previous value at i is same as current , to handle that

            int j = i + 1, k = n - 1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum > 0) {
                    k--;
                } else if(sum < 0) {
                    j++;
                } else { // sum == 0 || Store the triplet
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++; k--;
                    
                    while(j < k && nums[j] == nums[j - 1]) j++; // if the previous and current value at j is same , to handle that
                }

            }
        }
        return ans;
    }
};