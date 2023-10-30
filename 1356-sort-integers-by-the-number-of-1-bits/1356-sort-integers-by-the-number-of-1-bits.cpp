class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        map<int, vector<int>> um;
        
        for(auto x: arr){
            int val = x;
            int count = 0;
            while(x > 0){
                if(x % 2 == 1){
                    count++;   
                }
                x /= 2;
            }
            um[count].push_back(val);
        }
        
        vector<int> ans;
        auto it = um.begin();
        while(it != um.end()){
            vector<int> temp = it->second;
            sort(temp.begin(), temp.end());
            for(auto x: temp){
                ans.push_back(x);
            }
            it++;
        }
        
        return ans;
    }
};