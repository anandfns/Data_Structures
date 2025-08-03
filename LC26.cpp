class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0; //freq
        int idx = 1; //to swap the unique element with the duplicate one

        for(int i = 0; i < nums.size() - 1; i++) { // -1 because we are using i+1 in inside block , that will go beyond the boundary if i==size
            if(nums[i] != nums[i+1]) {
                k++;
                nums[idx++] = nums[i+1];
            }
        }
        return k + 1; //k will always be less by 1 value, you can initialize k=1 if you want
    }
};