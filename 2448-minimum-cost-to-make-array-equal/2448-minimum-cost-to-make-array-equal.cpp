class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        long long ans = 0;
        long long totalNums = 0;

        vector<pair<int,int>> vec;
        
        for(int i = 0; i < n; i++){
            vec.push_back({nums[i], cost[i]});
        }
        
        
        sort(vec.begin(), vec.end());
        
        
        
        for(int i = 0; i < n; i++){
            totalNums += cost[i];
        }
        
        long long medianIndex = (totalNums + 1) / 2;
        
        
        
        long long count = 0;
        int median = -1;

        for(int i = 0; i < n; i++){
            count += vec[i].second;
            if(count >= medianIndex){
                median = vec[i].first;
                break;
            }
        }
        
        cout<<medianIndex<<endl;
        
        
        for(int i = 0; i < n; i++){
            ans += abs(nums[i] - median) * (long long)cost[i];
        }
        
        return ans;
        
        
        
    }
};