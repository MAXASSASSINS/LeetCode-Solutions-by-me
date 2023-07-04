class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int> (n));
        vector<vector<bool>> visited(m, vector<bool> (n));
        
        queue<pair<int, pair<int,int>>> q;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    q.push({0, {i, j}});
                    visited[i][j] = true;
                }
            }
        }
        
        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, -1, 0, 1};
        
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            
            int row = u.second.first;
            int col = u.second.second;
            int dis = u.first;
            
            ans[row][col] = dis;
            
            for(int i = 0; i < 4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                
                if(nrow > -1 && nrow < m && ncol > -1 && ncol < n && !visited[nrow][ncol]){
                    visited[nrow][ncol] = true;
                    q.push({dis + 1, {nrow, ncol}});
                }
            }   
        }
        
        return ans;
        
        
    }
};