class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_map<int,int> m;
        
        int ans = 0;
        int count = 0;
        for(int i = 1; m.size() < n; i++){
            auto it = m.find(k - i);
            if(it == m.end()){
                ans += i;
                m[i] = 1;
                count++;
            }
        }
        
        return ans;
    }
};