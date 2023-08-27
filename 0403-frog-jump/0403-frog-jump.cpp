class Solution {
public:
    
    int bs(vector<int> &stones, int st, int en, int target){
        while(st <= en){
            int mid = st + (en - st)/2;
            int stone = stones[mid];
            if(stone == target) return mid;
            else if (stone > target) en = mid - 1;
            else st = mid + 1;
        }
        
        return -1;
    }
    
    bool solve(vector<int> &stones, int index, int k, vector<vector<int>> &dp){
        if(index >= stones.size()) return false;
        if(index == stones.size() - 1) return true;
        
        if(dp[index][k] != -1) return dp[index][k];
        
        bool j1 = false, j2 = false, j3 = false;
        
        int i1 = bs(stones, index + 1, stones.size() - 1, stones[index] + k - 1);
        int i2 = bs(stones, index + 1, stones.size() - 1, stones[index] + k);
        int i3 = bs(stones, index + 1, stones.size() - 1, stones[index] + k + 1);
        
        if(i1 != -1){
            j1 = solve(stones, i1, k - 1, dp);
        }
        
        if(i2 != -1){
            j2 = solve(stones, i2, k, dp);
        }
        
        if(i3 != -1){
            j3 = solve(stones, i3, k + 1, dp);
        }
        
        return dp[index][k] = j1 || j2 || j3;
    }
    
    
    
    bool canCross(vector<int>& stones) {
        vector<vector<int>> dp(stones.size() + 1, vector<int>(2500, -1));
        return solve(stones, 0, 0, dp);
    }
};