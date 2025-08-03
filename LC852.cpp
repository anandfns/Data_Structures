class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int st = 1;
        int end = arr.size() - 2;
        
        while(st <= end) {
            int mid = st + (end - st)/2;
            if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]) return mid;
            
            //checkin if the mid is on the left slope of the mountain or on the right slope
            if(arr[mid - 1] < arr[mid]) st = mid + 1; //on left slope
            else end = mid - 1; //on right slope
        }

        return -1;
    }
};