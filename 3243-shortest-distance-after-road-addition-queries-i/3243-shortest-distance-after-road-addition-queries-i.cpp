class Solution {
public:
    int bfs(vector<vector<int>> &adjList, int n){
        int src = 0;
        int dest = n - 1;
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(src);
        visited[src] = true;
        
        int level = 0;
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i = 0; i < size; i++){
                int node = q.front();
                if(node == dest) return level;
                q.pop();

                for(int j = 0; j < adjList[node].size(); j++){
                    int adjNode = adjList[node][j];
                    if(!visited[adjNode]){
                        visited[adjNode] = true;
                        q.push(adjNode);
                    }
                }
            } 
            
            level++;
        }
        
        return -1;
        
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> vec(n, vector<int>());
        
        for(int i = 0; i < n - 1; i++){
            vec[i].push_back(i + 1);
        }
        
        vector<int> res;
        
        for(auto q: queries){
            int st = q[0];
            int en = q[1];
            vec[st].push_back(en);
            int steps = bfs(vec, n);
            res.push_back(steps);
        }
        
        return res;
    }
};