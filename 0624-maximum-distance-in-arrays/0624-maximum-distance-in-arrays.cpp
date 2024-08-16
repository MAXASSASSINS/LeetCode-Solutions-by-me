class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        sort(arrays.begin(), arrays.end());
        int mini = arrays[0][0];
        int maxi = INT_MIN;
        int diff = INT_MIN;
        for(int i = 1; i < n; i++){
            int m = arrays[i].size();
            maxi = max(maxi, arrays[i][m - 1]);
        }
        
        diff = maxi - mini;
        
        cout<<maxi<<mini;
        
        if(maxi < arrays[0][arrays[0].size() - 1]){
            diff = max(diff, arrays[0][arrays[0].size() - 1] - arrays[1][0]);
        }
        
        return diff;
    }
};