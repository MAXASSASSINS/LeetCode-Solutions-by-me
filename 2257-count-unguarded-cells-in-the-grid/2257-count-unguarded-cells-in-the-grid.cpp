class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        // 0 - not visited
        // 1 - visited
        // 2 - wall
        // 3 - guard
        
        for(auto g: guards){
            int row = g[0];
            int col = g[1];
            grid[row][col] = 3;
        }
        
        for(auto w: walls){
            int row = w[0];
            int col = w[1];
            grid[row][col] = 2;
        }
        
        queue<vector<int>> q(guards.begin(), guards.end());
        
        while(!q.empty()){
            auto g = q.front();
            q.pop();
            int row = g[0];
            int col = g[1];
            
            // top
            int i = row - 1;
            while(i >= 0 && (grid[i][col] == 0 || grid[i][col] == 1)){
                grid[i][col] = 1;
                i--;
            }
            
            // bottom
            i = row + 1;
            while(i < m && (grid[i][col] == 0 || grid[i][col] == 1)){
                grid[i][col] = 1;
                i++;
            }
             
            // left
            int j = col - 1;
            while(j >= 0 && (grid[row][j] == 0 || grid[row][j] == 1)){
                grid[row][j] = 1;
                j--;
            }

            // right
            j = col + 1;
            while(j < n && (grid[row][j] == 0 || grid[row][j] == 1)){
                grid[row][j] = 1;
                j++;
            }
        }
        
        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cout<<grid[i][j]<<"\t";
                if(grid[i][j] == 0) count++;
            }
            cout<<endl;
        }
        
        
        
        return count;
        
    }
};