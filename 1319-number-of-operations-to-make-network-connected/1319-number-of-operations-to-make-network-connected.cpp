class Solution {
public:
    void bfs(int st, vector<bool> &visited, vector<int> adj[]){
        queue<int> q;
        q.push(st);
        visited[st] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto n: adj[node]){
                if(!visited[n]){
                    visited[n] = true;
                    q.push(n);
                }
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1;
        }
        vector<int> adj[n];
        for(int i = 0; i < connections.size(); i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        
        // for(int i = 0; i < n + 1; i++){
        //     for(auto n: adj[i]){
        //         cout<<n<<" ";
        //     }
        //     cout<<endl;
        // }
        
        int count = 0;
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                count++;
                bfs(i, visited, adj);
            }
        }
        count--;
        return count;
    }
};