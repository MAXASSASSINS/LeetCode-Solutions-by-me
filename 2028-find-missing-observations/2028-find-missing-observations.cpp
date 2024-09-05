class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int total = mean * (m + n);
        int rollSum = 0;
        for(auto roll: rolls) rollSum += roll;
        
        int reqSum = total - rollSum;
        
        if(reqSum < n * 1 || reqSum > n * 6){
            return {};
        }
        
        cout<<total<<"\t"<<rollSum<<"\t"<<reqSum<<endl;
        
        vector<int> ans(n, 1);
        reqSum -= n;
        
        for(int i = 0; i < n && reqSum >= 0; i++){
            if(reqSum >= 5){
                ans[i] = 6;
                reqSum -= 5;
            }
            else{
                ans[i] += reqSum;
                reqSum = 0;
            }
        }
        
        return ans;
    }
};