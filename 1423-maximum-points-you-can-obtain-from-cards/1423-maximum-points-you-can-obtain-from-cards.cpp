class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int cnt = n - k;
        int sum = 0;
        int total = 0;
        
        for(int i = 0; i < cnt; i++){
            sum += cardPoints[i];
            total += cardPoints[i];
        }
        
        int mini = sum;
        
        for(int i = cnt; i < n; i++){
            sum -= cardPoints[i - cnt];
            sum += cardPoints[i];
            total += cardPoints[i];
            mini = min(sum, mini);
        }
        
        if(k == n) return total;
        
        return total - mini;
        
    }
};