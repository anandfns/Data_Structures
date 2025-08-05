//***************Both the Solutions are accepted*****************

class Solution { // O(log( m * n ))
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0;
        int m = matrix.size();
        int n = matrix[i].size();
        int mid = 0;

        int rowSt = 0;
        int rowEnd = m - 1;
        while(rowSt <= rowEnd) { // Binary search for finding the desired row
            mid = rowSt + (rowEnd - rowSt)/2;

            if(matrix[mid][0] <= target && target <= matrix[mid][n-1]) {
                i = mid;
                break;
            } else if(matrix[mid][n-1] <= target) {
                rowSt = mid + 1;
            } else { // target < matrix[mid][0]
                rowEnd = mid - 1;
            }
        }

        int st = 0;
        int end = n - 1;
        while(st <= end) {
            mid = st + (end - st)/2;
            
            if(matrix[i][mid] == target) return true;
            else if(matrix[i][mid] > target) end = mid - 1;
            else st = mid + 1;
        }

        return false;
    }
};


//**************************************************************************

class Solution { // O(m * log(n))
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        if(target < matrix[0][0] || matrix[m - 1][n - 1] < target) return false;

        int row = 0;

        for(int i = 0; i < m; i++) { // Linear search for finding the desired row
            if(target > matrix[i][n - 1]) continue;
            else if(matrix[i][0] <= target && target <= matrix[i][n - 1]) {
                row = i;
                break;
            }
        }

        // Binary search on the desired row
        int st = 0;
        int end = n - 1;
        while(st <= end) {
            int mid = st + (end - st) / 2;

            if(matrix[row][mid] == target) return true;

            if(target > matrix[row][mid]) st = mid + 1;
            else end = mid - 1;
        }

        return false;
    }
};