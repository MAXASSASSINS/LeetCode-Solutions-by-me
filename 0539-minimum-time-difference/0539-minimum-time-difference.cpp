class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        sort(timePoints.begin(), timePoints.end());
        int res = INT_MAX;
        for(int i = 1; i < n; i++){
            string curr = timePoints[i];
            string prev = timePoints[i - 1];
            
            int diff = stoi(curr.substr(3, 2)) - stoi(prev.substr(3, 2));
            diff += 60 * (stoi(curr.substr(0,2)) -stoi(prev.substr(0, 2)));
            res = min(res, diff);
        }
        
        string curr = timePoints[0];
        string prev = timePoints[n - 1];
        
        int diff = stoi(curr.substr(3, 2)) - stoi(prev.substr(3, 2));
        diff += 60 * (stoi(curr.substr(0,2)) + 24 - stoi(prev.substr(0, 2)));
        
        res = min(res, diff);
        
        return res;
    }
};