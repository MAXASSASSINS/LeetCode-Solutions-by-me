class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>> pq;
        
        int ans = INT_MIN;
        
        for(int i = 0; i < n; i++){
            while(!pq.empty() && i - pq.top().second > k){
                pq.pop();
            }
            
            int f = pq.empty() ? INT_MIN : (pq.top().first + nums[i]);
            int s = nums[i];
            int maxi = max(f, s);
            ans = max(ans, maxi);
            pq.push({maxi, i});
        }
        
        return ans;
        
    }
};