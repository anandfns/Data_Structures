// Brute Force : O(n1 + n2) and SC : O(n1 + n2)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        vector<int> ans;
        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] < nums2[j]) {
                ans.push_back(nums1[i++]);
            } else {
                ans.push_back(nums2[j++]);
            }
        }
        while(i < nums1.size()) ans.push_back(nums1[i++]);
        while(j < nums2.size()) ans.push_back(nums2[j++]);

        int n = nums1.size() + nums2.size();
        if(n%2 != 0) return ans[n/2];
        return (double)((double)ans[n/2] + (double)ans[n/2 - 1]) / (double)2;
    }
};

