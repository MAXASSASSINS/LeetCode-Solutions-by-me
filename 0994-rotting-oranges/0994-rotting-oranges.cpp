class Solution {
public:
    int bfs(vector<vector<int>> &grid){
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));

        queue<vector<int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    vector<int> temp = {i, j, 0};
                    q.push(temp);
                    visited[i][j] = true;
                }
            }
        }

        int timer = 0;
        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, -1, 0, 1};
        while(!q.empty()){
            vector<int> temp = q.front();
            q.pop();
            int row = temp[0];
            int col = temp[1];
            int counter = temp[2];
            timer = max(timer, counter);

            for(int i = 0; i < 4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1 && !visited[nrow][ncol]){
                    vector<int> temp2 = {nrow, ncol, counter + 1};
                    q.push(temp2);
                    visited[nrow][ncol] = true;
                }
            }
            
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    return -1;
                }
            }
        }

        return timer;

    }


    int orangesRotting(vector<vector<int>>& grid) {
        return bfs(grid);
    }
};