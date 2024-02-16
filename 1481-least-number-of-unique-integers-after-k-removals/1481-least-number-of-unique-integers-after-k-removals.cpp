class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> m;
        for(auto n: arr){
            m[n]++;
        }
        
        vector<vector<int>> vec;
        auto it = m.begin();
        while(it != m.end()){
            vec.push_back({it->second, it->first});
            it++;
        }
        
        sort(vec.begin(), vec.end());
        int i = 0;
        while(k > 0 && i < vec.size()){
            int cnt = vec[i][0];
            if(k >= cnt){
                k -= cnt;
                vec[i][0] = 0;
            }
            else{
                vec[i][0] = k;
                k = 0;
            }
            i++;
        }
        
        
        for(int i = 0; i < vec.size(); i++){
            if(vec[i][0] != 0){
                return vec.size() - i;
            }
        }
        
        return 0;
        
    }
};