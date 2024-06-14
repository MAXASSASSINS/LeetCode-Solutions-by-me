class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        map<int,int> m;
        for(auto x: nums){
            m[x]++;
        }
        
        int ans = 0;
        auto it = m.begin();
        while(it != m.end()){
            int num = it->first;
            int freq = it->second;
            cout<<num<<"\t"<<freq<<endl;
            
            if(freq == 1){
                it++;
                continue;
            } 
            
            ans += freq - 1;
            it->second = 1;
            m[num + 1] += freq - 1;
            it++;
        }
        
        return ans;
    }
};