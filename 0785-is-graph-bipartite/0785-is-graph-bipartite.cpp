class Solution {
public:
    bool bfs(vector<vector<int>>& graph, vector<int> &color, int st){
        queue<int> q;
        q.push(st);
        color[st] = 0;
        
         while(!q.empty()){
            int u = q.front();
            int clr = color[u];
            q.pop();
            
            for(auto v: graph[u]){
                if(color[v] == -1){
                    color[v] = !clr;
                    q.push(v);
                }
                else if(color[v] == clr) return false;
            }
        }
        
        return true;
    }
    
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        
        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                if(bfs(graph, color, i) == false) return false;       
            }
        }        

        return true;        
    }
};