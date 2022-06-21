class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> indices;
        int n = matrix.size();
        int m = matrix.at(0).size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(matrix.at(i).at(j) == 0){
                    vector<int> temp = {i, j};
                    indices.push_back(temp);
                }
            }
        }
        int k = 0;
        while (k < indices.size()) {
            for (int i = 0; i < m; ++i) {
                matrix[indices.at(k).at(0)][i] = 0;
            }
            for (int i = 0; i < n; ++i) {
                matrix[i][indices.at(k).at(1)] = 0;
            }
            k++;
        }
    }
};