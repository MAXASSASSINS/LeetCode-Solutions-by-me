class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        int maxi = time[0];
        for(auto t: time){
            maxi = max(maxi, t);
        }
        
        long long low = 1;
        long long high = 1LL * maxi * totalTrips;
        
        while(low <= high){
            long long mid = low + (high - low)/2;
            long long temp = 0;
            for(auto t: time){
                temp += mid / t;
            }
            
            if(temp < totalTrips){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        
        return low;
        
        
    }
};