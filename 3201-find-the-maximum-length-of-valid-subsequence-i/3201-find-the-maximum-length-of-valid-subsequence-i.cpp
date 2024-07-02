class Solution {
public:
    int maximumLength(vector<int>& nums) {
        for(auto &x: nums){
            x %= 2;
        }
        
        int cnt = 0;
        int ans = 0;
        for(auto x: nums){
            if(x == 0) cnt++;
        }
        ans = max(cnt, ans);
        
        cnt = 0;
        for(auto x: nums){
            if(x == 1) cnt++;
        }
        ans = max(cnt, ans);
        
        
        cnt = 0;
        for(auto x: nums){
            if(cnt % 2 == 0 && x == 0){
                cnt++;
            }
            else if(cnt % 2 == 1 && x == 1){
                cnt++;
            }
        }
        ans = max(ans, cnt);
        
        cnt = 0;
        for(auto x: nums){
            if(cnt % 2 == 0 && x == 1){
                cnt++;
            }
            else if(cnt % 2 == 1 && x == 0){
                cnt++;
            }
        }
        ans = max(ans, cnt);
        
        return ans;
    }
};