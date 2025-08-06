class Solution { // TC : O(n2)
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        unordered_set<int> s;
        int n = grid.size();
        int a , b; // a ~ repeating , b ~ missing
        int expSum = 0 , actualSum = 0;

        //Finding Reapeating value ~ a
        for(int i=0; i<grid.size(); i++) { // nested loop - we are traversing the 2D vector here
            for(int j=0; j<grid[i].size(); j++) {
                actualSum += grid[i][j];
                if(s.find(grid[i][j]) != s.end()) {
                    a = grid[i][j];        // don't use break after this, or the actual Sum will give the wrong value
                }
                s.insert(grid[i][j]);
            }
        }

        // Finding missing value ~ b
        expSum = (n*n) * (n*n + 1) / 2;
        b = expSum + a - actualSum;
        return {a,b};
    }
};