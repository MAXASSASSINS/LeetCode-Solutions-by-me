class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination) return true;
        
        vector<int> adj[n];
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);             
        }
        
        
        vector<bool> visited(n);
        queue<int> q;
        q.push(source);
        visited[source] = true;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto x: adj[node]){
                if(!visited[x]){
                    visited[x] = true;
                    if(x == destination) return true;
                    q.push(x);                            
                }
            }
        }        
        
        return false;
            

    }
};