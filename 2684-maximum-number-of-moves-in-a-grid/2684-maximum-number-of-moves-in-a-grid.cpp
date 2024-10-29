class Solution {
public:
    
    bool isValid(vector<vector<int>> &grid, vector<vector<bool>> &visited, int row, int col, int nrow, int ncol){
        int m =  grid.size();
        int n = grid[0].size();
        
        if(nrow < 0 || nrow >= m || ncol >= n) return false;
        if(visited[nrow][ncol]) return false;
        if(grid[nrow][ncol] <= grid[row][col]) return false;
        return true;
    }
    
    int bfs(vector<vector<int>> &grid){
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int,int>> q;
        for(int i = 0; i < m; i++){
            q.push({i, 0});
            visited[i][0] = true;
        }
        
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto cell = q.front();
                q.pop();
                int row = cell.first;
                int col = cell.second;
                
                if(isValid(grid, visited, row, col, row, col + 1)){
                    q.push({row, col + 1});
                    visited[row][col + 1] = true;
                }
                if(isValid(grid, visited, row, col, row + 1, col + 1)){
                    q.push({row + 1, col + 1});
                    visited[row + 1][col + 1] = true;
                }
                if(isValid(grid, visited, row, col, row - 1, col + 1)){
                    q.push({row - 1, col + 1});
                    visited[row - 1][col + 1] = true;
                }
            }
            if(q.size() == 0) break;
            level++;
        }
        
        return level;
    }
    
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        
        return bfs(grid);
    }
};