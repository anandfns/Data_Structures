// Extreme Brute Force ~ TC : O(limit) and SC : O(k)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> vec;
        int limit = arr.size() + k;
        int idx = 0;
        for(int i=1; i <= limit; i++) {
            if(idx < arr.size() && arr[idx] == i) {
                idx++;
            } else {
                vec.push_back(i);
            }
        }

        return vec[k-1];
    }
};

// Brute Force ~ TC : O(n) and SC : O(1)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // Iterate through each number in the given sorted array
        for(int i = 0; i < arr.size(); i++) {
            // If the current array element is less than or equal to k,
            // it means this number is NOT missing and the k-th missing
            // number is pushed further by 1
            if(k >= arr[i]) 
                k++;  // Increment k to account for the number in the array
            else 
                break; // If arr[i] > k, the k-th missing number is found
        }
        // After the loop, k represents the k-th missing positive number
        return k;

    }
};

// Binary Search ~ TC : O(logN) and SC : O(1)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0;
        int high = arr.size() - 1;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int missing = arr[mid] - (mid+1);
            
            if(missing >= k) {
                high = mid - 1;
            } else { // missing < k
                low = mid + 1;
            }
        }

        // if(high == -1) return k;

        // required missing index == high
        // int howMuchMore = k - (arr[high] - (high+1));
        // return arr[high] + howMuchMore;

        // so we have to return the below 
        // arr[high] + k - (arr[high] - (high + 1));
        // arr[high] + k - arr[high] + high + 1
        // k + high + 1;
        // high + 1 + k
        // low + k

        // It can even resolve the condition of high == -1

        return low + k;
    }
};