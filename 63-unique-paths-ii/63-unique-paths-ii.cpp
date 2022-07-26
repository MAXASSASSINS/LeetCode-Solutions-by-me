class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rowSize = obstacleGrid.size();
        int colSize = obstacleGrid[0].size();
        if (obstacleGrid[rowSize - 1][colSize - 1] == 1 || obstacleGrid[0][0] == 1){
            return 0;
        }
        obstacleGrid[0][0] = 1;
        for (int i = 1; i < colSize; ++i) {
            if (obstacleGrid[0][i] == 1){
                obstacleGrid[0][i] = 0;
            }
            else{
                obstacleGrid[0][i] = obstacleGrid[0][i - 1];
            }
        }

        for (int i = 1; i < rowSize; ++i) {
            if(obstacleGrid[i][0] == 1){
                obstacleGrid[i][0]  = 0;
            }
            else{
                obstacleGrid[i][0] = obstacleGrid[i - 1][0];
            }
        }

        for (int i = 1; i < rowSize; ++i) {
            for (int j = 1; j < colSize; ++j) {
                if(obstacleGrid[i][j] == 1){
                    obstacleGrid[i][j] = 0;
                    continue;
                }
                obstacleGrid[i][j] = obstacleGrid[i][j - 1] + obstacleGrid[i - 1][j];
            }
        }
        return obstacleGrid[rowSize - 1][colSize - 1];
    }
};