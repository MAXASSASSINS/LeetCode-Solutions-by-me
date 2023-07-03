//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool dfs(int V, vector<int> adj[], vector<bool> &visited, int node, int parentNode){
        visited[node] = true;
        
        int ans = false;
        
        for(auto v: adj[node]){
            if(visited[v] && v != parentNode){
                return true;
            }
            if(!visited[v]){
                ans = ans || dfs(V, adj, visited, v, node);
            }
        }
        
        
        return ans;
        
    }
    
    bool bfs(int V, vector<int> adj[], vector<bool> &visited, int st){
        queue<pair<int,int>> q;
        q.push({st, -1});
        visited[st] = true;
        
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            
            for(auto v: adj[u.first]){
                if(visited[v] && v != u.second){
                    return true;
                }
                if(!visited[v]){
                    visited[v] = true;
                    q.push({v, u.first});
                }
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V);
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                // if(dfs(V, adj, visited, i, i)) return true;    
                if(bfs(V, adj, visited, i)) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends