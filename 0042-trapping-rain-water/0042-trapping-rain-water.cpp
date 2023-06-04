class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        int preMax[n];
        int suffMax[n];
        
        preMax[0] = height[0];
        suffMax[n - 1] = height[n - 1];
        
        for(int i = 1; i < n; i++){
            preMax[i] = max(preMax[i - 1], height[i]);
        }
        
        for(int i = n - 2; i >= 0; i--){
            suffMax[i] = max(suffMax[i + 1], height[i]);
        }
        
        
        int ans = 0;
        for(int i = 1; i < n - 1; i++){
            ans += min(preMax[i], suffMax[i]) - height[i];
        }
        
        
        return ans;
    }
};