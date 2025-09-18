// Merge Sort ~ TC : O(nlogn) ~ SC : O(n)
class Solution {
public:
    void merge(vector<int>&nums, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        while(left <= mid && right <= high) {
            if(nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            } else {
                temp.push_back(nums[right]);
                right++;
            }
        }

        while(left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }

        while(right <= high) {
            temp.push_back(nums[right]);
            right++;
        }

        for(int i=low; i<=high; i++) {
            nums[i] = temp[i - low];
        }
    }
    void mergeSort(vector<int>& nums, int low, int high) {
        if(low == high) return;

        int mid = low + (high-low)/2;

        mergeSort(nums, low, mid);
        mergeSort(nums, mid+1, high);
        merge(nums, low, mid, high);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};

// Quick Sort ~ TC : O(nlogn) ~ SC : O(1) we are not considering the recursion call stack
class Solution {
public:
    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[low];
        int i = low;
        int j = high;

        while(i < j) {
            while(nums[i] <= pivot && i <= high-1) i++;
            while(nums[j] > pivot && j >= low+1) j--;
            if(i < j) swap(nums[i], nums[j]);
        }

        swap(nums[low], nums[j]);
        return j;
    }

    void quickSort(vector<int>& nums, int low, int high) {
        if(low < high) {
            int PI = partition(nums, low, high);
            quickSort(nums, low, PI - 1);
            quickSort(nums, PI + 1, high);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
};