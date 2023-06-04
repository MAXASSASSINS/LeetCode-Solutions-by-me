class Solution {
public:
    void bfs(vector<int> adj[], vector<bool> &visited, int st){
        queue<int> q;
        q.push(st);
        visited[st] = true;
        
        while(!q.empty()){
            int v = q.front();
            q.pop();
            
            for(auto u: adj[v]){
                if(!visited[u]){
                    visited[u] = true;
                    q.push(u);
                }
            }
        }
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<bool> visited(n);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                ans++;
                bfs(adj, visited, i);
            }
        }
        
        return ans;
    }
};