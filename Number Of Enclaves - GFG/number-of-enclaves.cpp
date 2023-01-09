//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int n, int m, vector<vector<int>> &mat, vector<vector<bool>> &visited, int row, int col){
        visited[row][col] = true;
        
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};
        
        
        for(int i = 0; i < 4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && mat[nrow][ncol] == 1){
                dfs(n, m, mat, visited, nrow, ncol);
            }
        }
        
    }
    int solve(int n, int m, vector<vector<int>> mat)
    {
        int o = 1;
        vector<vector<bool>> visited(n, vector<bool>(m));
        for(int i = 0; i < n; i++){
            if(mat[i][0] == o){
                dfs(n, m, mat, visited, i, 0);
            }
            if(mat[i][m - 1] == o){
                dfs(n, m, mat, visited, i, m - 1);
            }
            
        }
        for(int i = 0; i < m; i++){
            if(mat[0][i] == o){
                dfs(n, m, mat, visited, 0, i);
            }
            if(mat[n - 1][i] == o){
                dfs(n, m, mat, visited, n - 1, i);
            }
        }
        
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == o && !visited[i][j]){
                    count++;
                }
            }
        }
        
        return count;
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        return solve(n, m, grid);
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends