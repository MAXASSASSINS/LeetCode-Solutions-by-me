class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int countElements = rows * cols;
        int rowst = 0;
        int colst = 0;
        int rowen = matrix.size() - 1;
        int colen = matrix[0].size() - 1;
        
        while (countElements > 0) {
            for (int i = colst; i <= colen && countElements > 0 ; ++i) {
                countElements--;
                ans.push_back(matrix[rowst][i]);
            }
            rowst++;

            for (int i = rowst; i <= rowen && countElements > 0; ++i) {
                ans.push_back(matrix[i][colen]);
                countElements--;
            }
            colen--;

            for (int i = colen; i >= colst && countElements > 0; --i) {
                ans.push_back(matrix[rowen][i]);
                countElements--;
            }
            rowen--;

            for (int i = rowen; i >= rowst && countElements > 0; --i) {
                ans.push_back(matrix[i][colst]);
                countElements--;
            }
            colst++;
        }
        return ans;
    }
};