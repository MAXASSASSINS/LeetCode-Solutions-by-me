class Solution {
public:
    int mod = 1e9 + 7;
    int solve(vector<int>& locations, int start, int finish, int fuel){
        if(fuel < 0) return 0;
        
        int ans = 0;
        if(start == finish){
            ans++;
        }
        for(int i = 0; i < locations.size(); i++){
            if(i != start){
                int fuelNeeded = abs(locations[i] - locations[start]);
                if(fuelNeeded <= fuel){
                    ans += solve(locations, i, finish, fuel - fuelNeeded);
                    ans %= mod;
                }
            }
        }
        
        return ans;
    }
    int solveMem(vector<int>& locations, int start, int finish, int fuel, vector<vector<int>> &dp){
        if(fuel < 0) return 0;
        
        int ans = 0;
        if(start == finish){
            ans++;
        }
        
        if(dp[start][fuel] != -1) return dp[start][fuel];
        
        for(int i = 0; i < locations.size(); i++){
            if(i != start){
                int fuelNeeded = abs(locations[i] - locations[start]);
                if(fuelNeeded <= fuel){
                    ans += solveMem(locations, i, finish, fuel - fuelNeeded, dp);
                    ans %= mod;
                }
            }
        }
        
        return dp[start][fuel] = ans %= mod;
    }
    
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        // return solve(locations, start, finish, fuel);
        
        vector<vector<int>> dp(locations.size() + 1, vector<int> (fuel + 1, -1));
        return solveMem(locations, start, finish, fuel, dp);
        
        // return ans;
    }
};