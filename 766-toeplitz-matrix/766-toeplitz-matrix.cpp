class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        if(n == 1 || m == 1){
            return true;
        }
        bool toeplitz = true;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(i - 1 >= 0 && j - 1 >= 0 && matrix[i][j] != matrix[i -1][j - 1]){
                    toeplitz = false;
                    break;
                }
            }
        }
        return toeplitz;
    }
};