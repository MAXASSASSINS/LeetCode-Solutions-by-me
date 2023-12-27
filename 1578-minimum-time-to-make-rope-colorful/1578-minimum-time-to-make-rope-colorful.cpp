class Solution {
public:
    
    int minCost(string colors, vector<int>& neededTime) {
        int cost = 0;
        
        int n = colors.length();
        
        int i = 0, j = 0;
        
        while(j < n){
            if(colors[i] == colors[j]){
                int maxi = INT_MIN;
                while(j < n && colors[i] == colors[j]){
                    maxi = max(maxi, neededTime[j]);
                    cost += neededTime[j];
                    j++;
                }
                cost -= maxi;                    
                i = j;
            }
            else{
                j++;
            }
        }
        
        return cost;
    }
    
};