class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> arrivals, departures;
        for(auto interval: intervals){
            arrivals.push_back(interval[0]);
            departures.push_back(interval[1]);
        }
        
        sort(arrivals.begin(), arrivals.end());
        sort(departures.begin(), departures.end());
        
        for(auto x: arrivals){
            cout<<x<<"\t";
        }
        cout<<endl;
        
        for(auto x: departures){
            cout<<x<<"\t";
        }
        cout<<endl;
        
        int cnt = 0;
        int i = 0, j = 0;
        int res = 0;
        while(i < n && j < n){
            if(arrivals[i] <= departures[j]){
                cnt++;
                i++;
            }
            else{
                cnt--;
                j++;
            }
            
            res = max(res, cnt);
        }
        
        return res;
    }
};