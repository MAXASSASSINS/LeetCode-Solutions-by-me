class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int, unordered_set<int>> adj;
        
        int maxi = 0;
        
        for(int i = 0; i < roads.size(); i++){
            adj[roads[i][0]].insert(roads[i][1]);
            adj[roads[i][1]].insert(roads[i][0]);
        }
        
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                int count = 0;
                auto it = adj[i].find(j);
                if(it != adj[i].end()){
                    count -= 1;
                }
                count += adj[i].size();
                count += adj[j].size();
                maxi = max(maxi, count);
            }
        }
        
        return maxi;
    }
};