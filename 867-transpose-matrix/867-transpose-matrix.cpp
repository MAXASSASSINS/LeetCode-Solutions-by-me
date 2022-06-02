class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>> &matrix) {
        vector<vector<int>> ans(matrix[0].size(), (vector<int>(matrix.size())));
        int l = 0,m = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                ans[l][m] =  matrix[i][j];
                l++;
            }
            m++;
            l = 0;
        }
        return ans;
    }
};