class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> vec(24);
        
        for(auto cand: candidates){
            int temp = cand;
            int bit = 0;
            while(temp > 0){
                if(temp % 2 == 1){
                    vec[bit]++;
                }
                temp /= 2;
                bit++;
            }
        }
        
        int res = *max_element(vec.begin(), vec.end());
        
        return res;
        
    }
};