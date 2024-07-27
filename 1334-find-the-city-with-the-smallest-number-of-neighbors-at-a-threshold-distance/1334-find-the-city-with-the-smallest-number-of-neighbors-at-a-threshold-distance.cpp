class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> mat(n, vector<int>(n, INT_MAX));
        
        int m = edges.size();
        
        for(int i = 0; i < m; i++){
            mat[edges[i][0]][edges[i][1]] = edges[i][2];
            mat[edges[i][1]][edges[i][0]] = edges[i][2];
        }

        for(int j = 0; j < n; j++){
            mat[j][j] = 0;
        }



        for(int k = 0; k < n ; k++){
            for(int i = 0; i < n ; i++){
                for(int j = 0; j < n ; j++){
                    if(mat[i][k] != INT_MAX && mat[k][j] != INT_MAX){
                        mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                    }
                }
            }
        }

        int city = -1;
        
        int prev = INT_MAX;
        
        
        for(int i = 0; i < n ; i++){
            int curr = 0;

            for(int j = 0; j < n ; j++){
                if(mat[i][j] <= distanceThreshold){
                    curr++;
                } 
            }
            
            if(curr <= prev){
                prev = curr;  
                city = i;
            }            
        } 
        
        return city;
    }
};