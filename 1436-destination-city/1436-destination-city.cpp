class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> fi, sec;

        for(auto path: paths){
            fi.insert(path[0]);
            sec.insert(path[1]);
        }
        
        for(auto it: sec){
            if(fi.find(it) == fi.end()){
                return it;
            }
        }
        
        
        return "";
        
        
    }
};