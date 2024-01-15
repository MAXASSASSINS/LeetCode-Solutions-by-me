class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans;
        unordered_map<int, int> lossCnt;
        
        unordered_set<int> allP;
        
        for(auto vec: matches){
            int loser = vec[1];
            lossCnt[loser]++;
            allP.insert(vec[0]);
        }
        
        vector<int> ls2;
        for(auto it = lossCnt.begin(); it != lossCnt.end(); it++){
            if(it->second == 1){
                ls2.push_back(it->first);
            }
        }
        
        
        vector<int> ls1;
        for(auto it = allP.begin(); it != allP.end(); it++){
            if(lossCnt.find(*it) == lossCnt.end()){
                ls1.push_back(*it);
            }
        }
        
        sort(ls1.begin(), ls1.end());
        sort(ls2.begin(), ls2.end());
        
        
        ans.push_back(ls1);
        ans.push_back(ls2);
        
        return ans;
        
    }
};