class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size();
        int m = worker.size();
        
        vector<pair<int,int>> vec;
        for(int i = 0; i < n; i++){
            vec.push_back({profit[i], difficulty[i]});
        }
        
        sort(vec.begin(), vec.end(), greater<pair<int,int>>());
        
        sort(worker.begin(), worker.end(), greater<int>());
        
        for(auto x: worker){
            cout<<x<<'\t';
        }
        cout<<endl;
        
        for(auto p: vec){
            cout<<p.first<<"\t"<<p.second<<endl;
        }
        
        int total = 0;
        int i = 0;
        int j = 0;
        while(i < n && j < m){
            auto p = vec[i];
            int diff = p.second;
            int prof = p.first;
            int wor = worker[j];
            if(wor >= diff){
                cout<<wor<<"\t"<<diff<<endl;
                total += prof;
                j++;
            }
            else{
                i++;
            }
        }
        
        return total;
        
    }
};