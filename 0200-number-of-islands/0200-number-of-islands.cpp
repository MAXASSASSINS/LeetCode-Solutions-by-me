class Solution {
public:
    void bfs(vector<vector<char>> &grid, int r, int c){
        queue<pair<int,int>> q;
        q.push({r, c});
        grid[r][c] = '2';
        
        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, -1, 0, 1};
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int row = p.first;
            int col = p.second;
            
            for(int i = 0; i < 4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                
                if(nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size() && grid[nrow][ncol] == '1'){
                    q.push({nrow, ncol});
                    grid[nrow][ncol] = '2';
                }    
            }
            
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int count = 0;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    count += 1;
                    bfs(grid, i, j);
                }
            }
        }
        
        return count;
    }
};