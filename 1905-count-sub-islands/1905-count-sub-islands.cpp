class Solution {
public:
    int checkSubIslandCond(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int row, int col) {
        bool subIsland = true;
        int m = grid2.size();
        int n = grid2[0].size();
        
        queue<pair<int,int>> q;
        q.push({row, col});
        grid2[row][col] = 2;
        
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            if(grid1[node.first][node.second] != 1) subIsland = false;
            
            for(int i = 0; i < 4; i++){
                int nrow = node.first + drow[i];
                int ncol = node.second + dcol[i];
                
                if(nrow >= 0 && ncol >= 0 && nrow < m && ncol < n && grid2[nrow][ncol] == 1){
                    grid2[nrow][ncol] = 2;
                    q.push({nrow, ncol});
                }
                
            }
        }
        
        return subIsland;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid2.size();
        int n = grid2[0].size();
        
        int count = 0;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid2[i][j] == 1){
                    count += checkSubIslandCond(grid1, grid2, i, j);
                }
            }
        }
        
        return count;
    }
};