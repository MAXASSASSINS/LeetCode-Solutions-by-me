class Solution {
public:
    
    
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        
        int n = grid.size();
        vector<vector<int>> dis(n, vector<int>(n, INT_MAX));
        
        queue<vector<int>> q;
        q.push({0,0,1});
        dis[0][0] = 1;
        
        while(!q.empty()){
            auto vec = q.front();
            q.pop();
            
            int row = vec[0];
            int col = vec[1];
            int dist = vec[2];
            
            for(int i = -1; i <= 1; i++){
                for(int j = -1; j <= 1; j++){
                    int new_row = row + i;
                    int new_col = col + j;
                    
                    if(new_row < n && new_col < n && new_row > -1 && new_col > -1 && grid[new_row][new_col] == 0 && dis[new_row][new_col] > dist + 1){
                        q.push({new_row, new_col, dist + 1});
                        dis[new_row][new_col] = dist + 1;
                    }
                    
                }
            }
        }
        
        
        
        if(dis[n - 1][n - 1] == INT_MAX) return -1;
        
        return dis[n - 1][n - 1];
    }
};