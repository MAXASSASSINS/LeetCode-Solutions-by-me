
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> ans(r, vector<int>(c));
        int rows = mat.size();
        int cols = mat.at(0).size();
        if(r * c != rows * cols){
            return mat;
        }
        int i = 0;

        int l = 0;
        int m = 0;
        while (i < rows){
            int j = 0;
            while (j < cols){
                 ans[l][m] = mat[i][j];
                 m++;
                 if(m == c){
                     l++;
                     m = 0;
                 }
                j++;
            }
            i++;
        }
        return ans;
    }
};