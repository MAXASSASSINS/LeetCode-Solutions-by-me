class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n1 = -1, n2 = -1;   
        int c1 = 0, c2 = 0;
        int n = nums.size();
        for(auto num: nums){
            if(num == n1){
                c1++;
            }
            else if(num == n2){
                c2++;
            }
            else if(c1 == 0){
                n1 = num;
                c1 = 1;
            }
            else if(c2 == 0){
                n2 = num;
                c2 = 1;
            }
            else{ 
                c1--;
                c2--;
            }
        }

        c1 = 0;
        c2 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == n1){
                c1++;
            }
            if(nums[i] == n2){
                c2++;
            }
        }
        vector<int> ans;
        
        if(c1 > n /3){
            ans.push_back(n1);
        }
        
        if(n1 != n2 && c2 > n/ 3){
            ans.push_back(n2);
        }
        return ans;
    }
};