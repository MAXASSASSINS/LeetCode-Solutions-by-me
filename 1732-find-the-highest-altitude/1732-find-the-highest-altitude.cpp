class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        int curr = 0;
        for(auto g: gain){
            curr = curr + g;
            ans = max(ans, curr);
        }
        
        return ans;
    }
};