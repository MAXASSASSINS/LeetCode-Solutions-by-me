class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> vec;
        for(auto i: intervals){
            vec.push_back({i[1], i[0]});
        }
        
        sort(vec.begin(), vec.end());
        
        
        int count = 1;
        int end = vec[0][0];
        for(int i = 1; i < vec.size(); i++){
            auto curr = vec[i];
            if(end <= curr[1]){
                end = curr[0];
                count++;
            }
        }
        
        
        return intervals.size() - count;
    }
};