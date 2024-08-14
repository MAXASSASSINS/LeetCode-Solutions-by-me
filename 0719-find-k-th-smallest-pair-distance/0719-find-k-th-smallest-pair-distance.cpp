class Solution {
public:
    int solve(vector<int>& nums, int maxDistance) {
        int count = 0;
        int arraySize = nums.size();
        int left = 0;

        for (int right = 0; right < arraySize; ++right) {
            // Adjust the left pointer to maintain the window with distances <=
            // maxDistance
            while (nums[right] - nums[left] > maxDistance) {
                ++left;
            }
            // Add the number of valid pairs ending at the current right index
            count += right - left;
        }
        return count;
    }
    
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mini = INT_MAX;
        int maxi = nums[n - 1] - nums[0];
        
        for(int i = 1; i < n; i++){
            mini = min(mini, nums[i] - nums[i - 1]);
        }
        
        int low = 0;
        int high = maxi;
        
        while(low <= high){
            int mid = (low + high) / 2;
            
            int pairs = solve(nums, mid);
            cout<<mid<<"\t"<<pairs<<endl;
            
            if(pairs >= k){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        
        return low;
    }
};