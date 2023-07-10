class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {             
        vector<pair<int,int>> adj[n];
        
        for(int i = 0; i < flights.size(); i++){
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});    
        }
        
        vector<int> dis(n, INT_MAX);
        dis[src] = 0;
        
        // priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        queue<vector<int>> pq;
        pq.push({src, 0, 0});
        
        while(!pq.empty()){
            auto it = pq.front();
            pq.pop();
            
            int node = it[0];
            int distance = it[1];
            int hop = it[2];
            
            for(auto pair: adj[node]){
                int adjNode = pair.first;
                int egWt = pair.second;
                
                int newDis = distance + egWt;
                
                if(dis[adjNode] > newDis && hop <= k){
                    dis[adjNode] = newDis;
                    pq.push({adjNode, newDis, hop + 1});
                }
            }
        }
        
        return dis[dst] == INT_MAX ? -1 : dis[dst];
        
        
    }
};