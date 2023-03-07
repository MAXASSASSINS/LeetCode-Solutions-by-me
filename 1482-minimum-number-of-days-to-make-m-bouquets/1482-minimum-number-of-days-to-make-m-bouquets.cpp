class Solution {
public:
    bool possible(int mid, vector<int> &vec, int m, int k){
        int n = vec.size();
        int temp = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(vec[i] <= mid){
                temp++;
            }
            else{
                temp = 0;
            }
            
            if(temp == k){
                temp = 0;
                ans++;
            }
            
            if(ans == m) return true;
        }
        
        return false;
        
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int n = bloomDay.size();
        if((long long)m * k  > (long long)n) return -1;
        auto it1 = min_element(bloomDay.begin(), bloomDay.begin() + n);
        auto it2 = max_element(bloomDay.begin(), bloomDay.begin() + n);
        
        int low = *it1;
        int high = *it2;
        
        while(low <= high){
            int mid = low + (high - low) /2 ;
            if(possible(mid, bloomDay, m, k)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        
        return low;
        
    }
};