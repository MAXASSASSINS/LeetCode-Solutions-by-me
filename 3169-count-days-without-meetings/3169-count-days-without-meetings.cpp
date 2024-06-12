class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        int cnt = 0;
        vector<int> starts, ends;
        for(auto meet: meetings){
            starts.push_back(meet[0]);
            ends.push_back(meet[1]);
        }
        
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        
        for(int i = 1; i < n; i++){
            cnt += max(0, starts[i] - ends[i - 1] - 1);
        }
        
        cnt += max(0, starts[0] - 1);
        cnt += days - ends[n - 1];
        
        return cnt;
    }
};