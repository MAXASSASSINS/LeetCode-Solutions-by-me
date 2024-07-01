class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int ans = 0;
        
        for(int i = 0; i < arr.size(); i++){
            if(i - 3 >= 0 && arr[i - 3] % 2 == 1) ans--;
            if(arr[i] % 2 == 1) ans++;
            
            if(ans == 3) return true;
        }
        
        
        return ans == 3;
    }
};