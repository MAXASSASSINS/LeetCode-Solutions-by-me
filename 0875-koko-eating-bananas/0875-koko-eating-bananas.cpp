class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 1e9;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            long long total = 0;
            for(auto pile: piles){
                total += ceil((double)pile/mid);
            }
            if(total > h){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
    
    
};