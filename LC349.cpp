// 4-Approach

// 1 - Using Hashing + Extra vector + Sorting
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;

        for(int i=0; i<nums2.size(); i++) {
            if(i != 0 && nums2[i] == nums2[i-1]) continue;
            if(s.find(nums2[i]) != s.end()) {
                ans.push_back(nums2[i]);
            }
        }

        return ans;
    }
};

// 2 - Using Hashing + Two Pointers
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        unordered_set<int> s;

        int i = 0;
        int j = 0;
        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] < nums2[j]) i++;
            else if(nums1[i] > nums2[j]) j++;
            else {
                s.insert(nums1[i]);
                i++; j++;
            }
        }
        
        vector<int> ans(s.begin(), s.end());
        return ans;
    }
};

// Using Hash Map + additional vector
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, bool> seen;
        vector<int> ans;
        for(int val : nums1) {
            seen[val] = true;
        }

        for(int val : nums2) {
            if(seen.count(val) && seen[val]) {
                ans.push_back(val);
                seen[val] = false;
            }
        }

        return ans;
    }
};

// Using Binary Search ~ TC : O(NlogN + MlogM) ~ For this case Two pointer is more Efficient
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;

        for(int i=0; i<nums1.size(); i++) {
            if(i > 0 && nums1[i] == nums1[i-1]) continue;
            if(binary_search(nums2.begin(), nums2.end(), nums1[i])) ans.push_back(nums1[i]);
        }

        return ans;
        
    }
};