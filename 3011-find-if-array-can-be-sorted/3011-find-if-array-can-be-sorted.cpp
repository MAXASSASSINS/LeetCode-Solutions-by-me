class Solution {
public:
    void buildMap(vector<int> &nums, unordered_map<int,int> &m){
        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            int cnt = 0;
            while(num != 0){
                if(num % 2 == 1){
                    cnt++;
                }
                num /= 2;
            }
            m[nums[i]] = cnt;
        }
    }
    
    bool canSortArray(vector<int>& nums) {
        unordered_map<int,int> m;
        int n = nums.size();
        buildMap(nums, m);
        
        int i = 1;
        for(int i = 1; i < n; i++){
            for(int j = 1; j < n; j++){
                if(nums[j] < nums[j - 1]){
                    if(m[nums[j]] == m[nums[j - 1]])
                        swap(nums[j], nums[j - 1]);
                    else return false;
                }
            }
        }
        
        return is_sorted(nums.begin(), nums.end());
        
    }
};