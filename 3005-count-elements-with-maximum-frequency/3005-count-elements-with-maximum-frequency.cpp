class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> m;
        int maxi = INT_MIN;
        for(int x: nums){
            m[x]++;
            maxi = max(maxi, m[x]);
        }
        
        int cnt = 0;
        for(auto it = m.begin(); it != m.end(); it++){
            if(it->second == maxi) cnt++;
        }
        
        return cnt * maxi;
    }
};