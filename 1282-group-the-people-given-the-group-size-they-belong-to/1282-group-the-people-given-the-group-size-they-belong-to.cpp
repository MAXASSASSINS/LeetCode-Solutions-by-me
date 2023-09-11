class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int maxi = *max_element(groupSizes.begin(), groupSizes.end());
        
        vector<vector<int>> vec(maxi + 1);
        int n = groupSizes.size();
        
        for(int i = 0; i < n; i++){
            vec[groupSizes[i]].push_back(i);
        }
        
        vector<vector<int>> ans;
        for(int i = 1; i < vec.size(); i++){
            
            for(int j = 0; j < vec[i].size(); j += i){
                vector<int> temp;
                for(int k = 0; k < i; k++){
                    temp.push_back(vec[i][j + k]);
                }
                ans.push_back(temp);
            }
        }
        
        return ans;
        
    }
};