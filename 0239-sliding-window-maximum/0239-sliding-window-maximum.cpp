class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int n = nums.size();
        vector<int> ans;
        
        for(int i = 0; i < k ; i++){
            if(dq.empty()){
                dq.push_front(i);
            }
            else if(nums[i] > nums[dq.back()]){
                while(!dq.empty() && nums[i] > nums[dq.back()]){
                    dq.pop_back();
                }
                dq.push_back(i);
            }
            else{
                dq.push_back(i);
            }
        }
        
        ans.push_back(nums[dq.front()]);
        
        for(int i = k; i < n; i++){
            if(dq.front() <= i - k){
                dq.pop_front();
            }
            if(dq.empty()){
                dq.push_front(i);
            }
            if(nums[i] > nums[dq.back()]){
                while(!dq.empty() && nums[i] > nums[dq.back()]){
                    dq.pop_back();
                }
                dq.push_back(i);
            }
            else{
                dq.push_back(i);
            }
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};