class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n, vector<int>());
        
        for(auto edge: edges){
            int st = edge[0];
            int en = edge[1];
            adjList[en].push_back(st);
        }
        
        for(auto adjNodes: adjList){
            for(auto node: adjNodes){
                cout<<node<<"\t";
            }
            cout<<endl;
        }
        
        int res = -1;
        for(int i = 0; i < n; i++){
            vector<int> adjNodes = adjList[i];
            if(adjNodes.size() == 0){
                if(res == -1){
                    res = i;
                }
                else{
                    return -1;
                }
            }
        }
        
        return res;
    }
};