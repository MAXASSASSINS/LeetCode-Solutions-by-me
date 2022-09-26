class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        int col = matrix[0].size() - 1;
        while (col >= 0 && row < matrix.size()){
            if (matrix[row][col] < target){
                row++;
            }
            else if (matrix[row][col] > target){
                col--;
            }
            else{
                return true;
            }
        }
        return false;
    }
};