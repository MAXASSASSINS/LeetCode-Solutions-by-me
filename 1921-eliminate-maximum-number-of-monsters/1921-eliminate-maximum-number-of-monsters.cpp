class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> time;
        for(int i = 0; i < n; i++){
            time.push_back(ceil((double)dist[i]/speed[i]));
        }
        
        sort(time.begin(), time.end());
        
        int timer = 1;
        int ans = 1;
        
        for(int i = 1; i < n; i++){
            if(time[i] <= timer){
                return ans;
            }
            timer++;
            ans++;
        }
        
        return ans;
        
    }
};