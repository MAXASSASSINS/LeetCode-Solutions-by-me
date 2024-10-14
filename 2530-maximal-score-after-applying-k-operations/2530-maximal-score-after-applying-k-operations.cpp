class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        long long sum = 0;
        while(k > 0){
            int val = pq.top();
            pq.pop();
            sum += val;
            int newVal = ceil(double(val) / 3);
            pq.push(newVal);
            k--;
        }
        
        return sum;
    }
};