class Solution {
public:
    int getIdx(vector<int> &nums, int target){
        int low = 0;
        int high = nums.size() - 1;
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            int x = nums[mid];
            if(target <= x){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        
        return high;
    }
    
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int low = 0;
        int high = nums.size();
        
        
//         while(low <= high){
//             int mid = low + (high - low)/2;
            
//             int idx = getIdx(nums, mid);
//             int numsToRight = n - idx - 1;
//             if(numsToRight == mid) return mid;
//             else if(numsToRight > mid){
//                 low = mid + 1;
//             }
//             else{
//                 high = mid - 1;
//             }
//         }
        
        
        for(int i = low; i <= high; i++){            
            int idx = getIdx(nums, i);
            cout<<idx<<"\t";
            int numsToRight = n - idx - 1;
            if(numsToRight == i) return i;
        }
        
        return -1;
    }
};