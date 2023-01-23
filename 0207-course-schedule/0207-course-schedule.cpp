class Solution {
public:
    bool cycle(int numCourses, vector<int> adj[], int node, vector<bool> &visited, vector<bool> &pathVisited){
        visited[node] = true;
        pathVisited[node] = true;
        
        for(auto n: adj[node]){
            if(!visited[n]){
                if(cycle(numCourses, adj, n, visited, pathVisited) == true) return true;
            }
            else if(pathVisited[n]){
                return true;
            }
        }
        
        pathVisited[node] = false;
        return false;
        
    }
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        int n = prerequisites.size();
        for(int i = 0; i < n; i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<bool> visited(numCourses);
        vector<bool> pathVisited(numCourses);
        
        for(int i = 0; i < numCourses; i++){
            if(!visited[i]){
                if(cycle(numCourses, adj, i, visited, pathVisited) == true) return false;
            }
        }
        return true;
    }
};