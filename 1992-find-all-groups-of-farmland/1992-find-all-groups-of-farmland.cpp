class Solution {
public:
    
    vector<int> bfs(vector<vector<int>> &land, int r, int c){
        int tr, br, tc, bc;
        tr = br = r;
        tc = bc = c;
        
        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, -1, 0, 1};

        queue<pair<int,int>> q;        
        q.push({r,c});
        land[r][c] = 2;
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int row = p.first;
            int col = p.second;
            
            for(int i = 0; i < 4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                
                if(nrow >= 0 && ncol >= 0 && nrow < land.size() && ncol < land[0].size() && land[nrow][ncol] == 1){
                    q.push({nrow, ncol});
                    land[nrow][ncol] = 2;
                    
                    if(nrow > br || ncol > bc){
                        br = nrow;
                        bc = ncol;
                    }
                }
            }
        }
        return {tr, tc, br, bc};
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        
        for(int i = 0; i < land.size(); i++){
            for(int j = 0; j < land[0].size(); j++){
                if(land[i][j] == 1){
                    vector<int> res = bfs(land, i, j);
                    ans.push_back(res);
                }
            }
        }
        
        return ans;
    }
};