//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
private:
    bool checkCycle(int V, vector<int> adj[], vector<bool> &visited, 
        vector<bool> &pathVisited, int node, vector<bool> &vec)
        {
            visited[node] = true;
            pathVisited[node] = true;
            
            for(auto n: adj[node]){
                if(!visited[n]){
                    if(checkCycle(V, adj, visited, pathVisited, n, vec) == true) return true;
                }
                else if(pathVisited[n]){
                    return true;
                }
            }
            vec[node] = true;
            pathVisited[node] = false;
            return false;
                   
        }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<bool> visited(V);
        vector<bool> pathVisited(V);
        vector<bool> temp(V);
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                checkCycle(V, adj, visited, pathVisited, i, temp);
            }
        }
        vector<int> ans;
        for(int i = 0; i < V; i++){
            if(temp[i]) ans.push_back(i);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends