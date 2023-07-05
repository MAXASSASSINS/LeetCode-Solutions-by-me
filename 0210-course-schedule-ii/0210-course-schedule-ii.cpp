class Solution {
public:
    bool dfs(vector<int> adj[], vector<bool> &visited, vector<bool> &pathVisited, int node, vector<int> &ans){
        visited[node] = true;
        pathVisited[node] = true;
        // ans.push_back(node);
        
        for(auto it: adj[node]){
            if(!visited[it]){
                if(dfs(adj, visited, pathVisited, it, ans)) return true;
            }
            else if(pathVisited[it]) return true;
        }
        
        pathVisited[node] = false;
        return false;
        
    }
        
    
    void bfs(vector<int> adj[], vector<bool> &visited, vector<int> &ans, int n){
        queue<int> q;
        q.push(n);
        visited[n] = true;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto it: adj[node]){
                if(!visited[it]){
                    visited[it] = true;
                    q.push(it);
                }
            }
        }
        
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses);
        vector<bool> pathVisited(numCourses);
        
        vector<int> adj[numCourses];
        
        for(auto vec: prerequisites){
            adj[vec[1]].push_back(vec[0]);
        }
        
        vector<int> ans;
        for(int i = 0; i < numCourses; i++){
            if(!visited[i]){
                if(dfs(adj, visited, pathVisited, i, ans)) return {};
            }
        }
        
        vector<int> inDegree(numCourses);
        for(int i = 0; i < numCourses; i++){
            for(auto it: adj[i]){
                inDegree[it]++;
            }
        }
         
        
        // applying kanh's algrorithm or topo sort
        queue<int> q;
        
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto it: adj[node]){
                inDegree[it]--;
                if(inDegree[it] == 0){
                    q.push(it);
                }
            }
        }
        return ans;
        
    }
};