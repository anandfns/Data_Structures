// resolve
// TC : O(m * n * (m+n)) and SC : O(m * n) 
class Solution {
public:
    void helper(vector<vector<int>>& matrix, pair<int, int> p) {
        // for hri
        for(int i=0; i<matrix[p.first].size(); i++) {
            matrix[p.first][i] = 0;
        }
        
        // for ver
        for(int i=0; i<matrix.size(); i++) {
            matrix[i][p.second] = 0;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> cords;
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0 ; j<matrix[i].size(); j++) {
                if(matrix[i][j] == 0) {
                    cords.push_back({i,j});
                }
            }
        }

        for(int i=0; i<cords.size(); i++) {
            helper(matrix, cords[i]);
        }
    }
};