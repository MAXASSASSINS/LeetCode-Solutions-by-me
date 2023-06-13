class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
    
    int solve(vector<int> &s, int k){
        int j = -1;
        int count = 0;
        
        unordered_map<int, int> m;
        for(int i = 0; i < s.size(); i++){
            m[s[i]]++;
            
            while(m.size() > k){
                j++;
                m[s[j]]--;
                if(m[s[j]] == 0) m.erase(s[j]);
            }
            
            count += i - j;
        }
        
        return count;
    }
};