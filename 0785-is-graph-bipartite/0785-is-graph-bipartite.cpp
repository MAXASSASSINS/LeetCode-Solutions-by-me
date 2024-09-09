class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> colored(n, -1);
        
        queue<int> q;
        
        for(int i = 0; i < n; i++){
            if(colored[i] == -1){
                q.push(i);
                colored[i] = 0;
                while(!q.empty()){
                    int node = q.front();
                    int color = colored[node];
                    q.pop();

                    for(int i = 0; i < graph[node].size(); i++){
                        int neighbour = graph[node][i];
                        if(colored[neighbour] == -1){
                            q.push(neighbour);
                            colored[neighbour] = !color;
                        }
                        else if(colored[neighbour] == color) return false;
                    }
                }
            }
        }
        
        return true;
        
    }
};