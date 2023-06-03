class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];
        
        for(int i = 0; i < n; i++){
            if(manager[i] != -1){                
                adj[manager[i]].push_back(i);
            }
        }
        
        int ans = 0;
        queue<pair<int, int>> q;
        vector<bool> visited(n);
        
        q.push({headID, 0});
        visited[headID] = true;
        

        while(!q.empty()){
            auto node = q.front();
            ans = max(ans, node.second);
            q.pop();
            
            for(auto i: adj[node.first]){
                if(!visited[i]){
                    q.push({i, node.second + informTime[node.first]});
                    visited[i] = true;
                }
            }
        }
        
        return ans;
    }
};