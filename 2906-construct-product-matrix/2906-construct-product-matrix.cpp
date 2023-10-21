class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mod = 12345;
        
        vector<vector<int>> prefix(n, vector<int>(m, 0));
        vector<vector<int>> suffix(n, vector<int>(m, 0));
        vector<vector<int>> ans(n, vector<int>(m, 0));
        
        
        int prod = 1;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                prefix[i][j] = prod;  
                prod *= grid[i][j] % mod;
                prod %= mod;
                cout<<prod<<" ";
            }
            cout<<endl;
        }
        
        prod = 1;
        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                suffix[i][j] = prod;
                prod *= grid[i][j] % mod;
                prod %= mod;
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans[i][j] = (prefix[i][j] * suffix[i][j]) % mod;
            }
        }
        
        return ans;
    }
};