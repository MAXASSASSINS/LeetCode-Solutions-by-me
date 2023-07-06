class Solution {
public:
    bool dfs(vector<vector<int>> &graph, vector<bool> &vis, vector<bool> &pathVis, int node, vector<int> &check){
        vis[node] = true;
        pathVis[node] = true;
        
        for(auto v: graph[node]){
            if(!vis[v]){
                if(dfs(graph, vis, pathVis, v, check) == true){
                    return true;   
                }              
            }
            else if(vis[v] == 1 && pathVis[v] == 1) return true;
        }
        
        pathVis[node] = false;
        check[node] = 1;
        
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n);
        vector<bool> pathVis(n);
        vector<int> check(n);
        vector<int> safe;
        
        
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(graph, vis, pathVis, i, check);       
            }
        }
        
        for(int i = 0; i < n; i++){
            if(check[i]) safe.push_back(i);
        }
        
        return safe;
    }
};