class Solution {
public:
    typedef vector<int> p;
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        
        priority_queue<p, vector<p>, greater<p>> pq;
        
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        for(int i = 0; i < k; i++){
            mini = min(mini, nums[i][0]);
            maxi = max(maxi, nums[i][0]);
            pq.push({nums[i][0], i, 0});
        }
        
        vector<int> range = {mini, maxi};
        
        while(true){
            auto elem = pq.top();
            pq.pop();
            int listno = elem[1];
            int index = elem[2];
            
            if(index + 1 == nums[listno].size()) break;
            
            int nextNo = nums[listno][index + 1];
            pq.push({nextNo, listno, index + 1});
            
            if(nextNo > maxi){
                maxi = nextNo;
            }
            
            mini = pq.top()[0];
            
            if(maxi - mini < range[1] - range[0]){
                range[1] = maxi;
                range[0] = mini;
            }
        }
        
        return range;
    }
};