class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int curArea = 0;
        int maxArea = 0;
        int i = 0;
        int j = n - 1;

        while(i < j) {
            int width = j - i;
            int height = min(heights[i] , heights[j]);

            curArea = width * height;
            maxArea = max(maxArea , curArea);
            
            if(heights[i] > heights[j]) j--;
            else i++;
        }

        return maxArea;
    }
};