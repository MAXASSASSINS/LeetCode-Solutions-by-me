class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int sr = -1, sc = -1;
        for(int i = 0;  i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    sr = i;
                    sc = j;
                    break;
                }
            }
            if(sr != -1 && sc != -1) break;
        }
        queue<pair<int, int>> q;
        
        q.push({sr, sc});
        grid[sr][sc] = 2;
        
        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, -1, 0, 1};
        
        int ans = 0;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            ans += 4;
            
            for(int i = 0; i < 4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                    if(grid[nrow][ncol] == 2){
                        ans -= 1;
                    } 
                    else if(grid[nrow][ncol] == 1){
                        ans -= 1;
                        q.push({nrow, ncol});
                        grid[nrow][ncol] = 2;
                    }
                }
            }
            
        }
        
        return ans;
        
    }
};