typedef pair<int,int> pi;

class Solution {
    
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n + 1];
        
        for(auto vec: times){
            adj[vec[0]].push_back({vec[1], vec[2]});
        }
        
        vector<int> dis(n + 1, INT_MAX);
        dis[k] = 0;
        dis[0] = 0;
        
        priority_queue<pi, vector<pi> , greater<pi>> pq;
        pq.push({k, 0});
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            int node = it.first;
            int time = it.second;
            
            for(auto pair: adj[node]){
                int adjNode = pair.first;
                int timeTake = pair.second;
                
                int newTime = timeTake + time;
                
                if(dis[adjNode] > newTime){
                    dis[adjNode] = newTime;
                    pq.push({adjNode, newTime});
                }
            }
        }
        
        int ans = *max_element(dis.begin(), dis.end());
        
        return ans == INT_MAX ? -1 : ans;
        
    }
};