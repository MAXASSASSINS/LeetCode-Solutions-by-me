class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = INT_MIN;
        int low = 0, high = height.size() - 1;
        while(low < high){
            int a = min(height[low], height[high]) * (high - low);
            ans = max(a, ans);
            if(height[low] < height[high]){
                low ++;
            }
            else{
                high--;
            }
        }
        return ans;
    }
};