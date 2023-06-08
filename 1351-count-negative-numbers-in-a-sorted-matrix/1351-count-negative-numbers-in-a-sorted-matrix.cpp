class Solution {
public:
    int binary(vector<int> &vec){
        int h = vec.size() - 1;
        int l = 0;
        
        int idx = -1;
        
        while(l <= h){
            int mid = l + (h - l)/2;
            if(vec[mid] < 0){
                idx = mid;
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        
        if(idx == -1) return 0;
        return vec.size() - idx;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        for(auto x: grid){
            count += binary(x);
        }
        return count;
    }
};