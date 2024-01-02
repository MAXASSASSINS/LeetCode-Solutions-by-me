class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> m;
        for(auto num: nums){
            m[num]++;
        }
        
        vector<vector<int>> vec;
        int prevSize = 0;
        
        do{
            prevSize = vec.size();
            vector<int> temp;
            auto it = m.begin();
            while(it != m.end()){
                if(it->second > 0){
                    temp.push_back(it->first);
                    it->second--;
                }
                it++;
            }
            if(temp.size() > 0){
                vec.push_back(temp);
            }
            
        }while(vec.size() != prevSize);
        
        return vec;
    }
};