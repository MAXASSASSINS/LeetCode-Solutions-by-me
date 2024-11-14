class Solution {
public:
    int countStores(int target, vector<int> &quantities){
        if(target == 0){
            return INT_MAX;
        }
        int count = 0;
        for(auto q: quantities){
            count += ceil(double(q)/target);
        }
        
        return count;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int maxi = *max_element(quantities.begin(), quantities.end());
        
        int low = 0;
        int high = maxi;
        
        while(low <= high){
            int mid = (low + high) / 2;
            int count = countStores(mid, quantities);
            if(count > n){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        
        return low;
    }
};