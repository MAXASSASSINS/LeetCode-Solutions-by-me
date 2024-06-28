class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int, int> m;
        for(auto road:  roads){
            m[road[0]]++;
            m[road[1]]++;
        }
        
        vector<pair<int,int>> vec;
        for(auto it = m.begin(); it != m.end(); it++){
            vec.push_back({it->second, it->first});
        }
        
        
        
        
        sort(vec.begin(), vec.end());
        for(auto x: vec){
            cout<<x.first<<"\t"<<x.second<<"\t\t\t";
        }
        cout<<endl;
        
        vector<int> vec2(n);
        int initialImp = n - m.size();
        
        for(int i = 0; i < vec.size(); i++){
            int node = vec[i].second;
            int imp =  initialImp + i + 1;
            vec2[node] = imp;
        }
        
        for(auto x: vec2){
            cout<<x<<"\t";
        }
        
        long long ans = 0;
        
        for(auto road: roads){
            ans += vec2[road[0]];
            ans += vec2[road[1]];
        }
        
        return ans;
        
    }
};