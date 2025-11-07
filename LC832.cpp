class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(int i=0; i<image.size(); i++) {
            int st = 0;
            int row = image[i].size()-1;
            while(st < row) {
                swap(image[i][st++], image[i][row--]);
            }

            for(int j=0; j<image[i].size(); j++) {
                if(image[i][j] == 1) image[i][j] = 0;
                else image[i][j] = 1;
            }
        }

        return image;
    }
};