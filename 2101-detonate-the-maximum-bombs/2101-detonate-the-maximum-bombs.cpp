class Solution {
public:
    
    bool willDetonate(const vector<int> &b1, const vector<int> &b2){
        int x = b2[0];
        int h = b1[0];
        int y = b2[1];
        int k = b1[1];
        int r = b1[2];
        
        return pow((x - h), 2) + pow((y - k), 2) - pow(r, 2) <= 0;
    }
    
    int bfs(vector<vector<int>> &bombs, int st){
        int count = 0;
        
        int n = bombs.size();
        
        vector<bool> visited(n);
        queue<vector<int>> q;
        
        
        visited[st] = true;
        q.push(bombs[st]);
        
        while(!q.empty()){
            vector<int> temp = q.front();
            count++;
            q.pop();
            
            for(int i = 0; i < n; i++){
                if(!visited[i] && willDetonate(temp, bombs[i])){
                    q.push(bombs[i]);
                    visited[i] = true;
                }
            }
    
        }
        
        return count;
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int maxi = 1;
        for(int i = 0; i < bombs.size(); i++){
            maxi = max(maxi, bfs(bombs, i));
        }
        
        return maxi;
    }
};