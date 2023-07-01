class Solution {
public:
    int solve(vector<int> &cookies, int k, int index, vector<int> &dis){
        if(index >= cookies.size()){
            auto it = max_element(dis.begin(), dis.end());
            return *it;
        }
        
        int ans = INT_MAX;
        
        for(int i = 0; i < k; i++){
            dis[i] += cookies[index];
            ans = min(ans, solve(cookies, k, index + 1, dis));
            dis[i] -= cookies[index];
        }
        
        return ans; 
    }
    
    
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> dis(k);
        return solve(cookies, k, 0, dis);
    }
};