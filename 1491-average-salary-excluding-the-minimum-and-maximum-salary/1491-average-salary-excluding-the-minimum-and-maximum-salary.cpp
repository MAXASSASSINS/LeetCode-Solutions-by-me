class Solution {
public:
    double average(vector<int>& salary) {
        int mini = salary[0];
        int maxi = salary[0];
        int size = salary.size();
        int sum = 0;
        for(auto n: salary){
            mini = min(n, mini);
            maxi = max(n, maxi);
            sum += n;
        }
        
        double ans = ((double)(sum - mini - maxi) / (size - 2));
        return ans;
    }
};