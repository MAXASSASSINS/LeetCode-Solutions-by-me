class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // unordered_map<int,vector<int>> m;
        // for(auto v: edges){
        //     m[v[0]].push_back(v[1]);
        //     m[v[1]].push_back(v[0]);
        // }
        if(edges[0][0] == edges[1][0]) return edges[0][0];
        if(edges[0][1] == edges[1][0]) return edges[0][1];
        if(edges[0][1] == edges[1][1]) return edges[0][1];
        return edges[0][0];
    }
};