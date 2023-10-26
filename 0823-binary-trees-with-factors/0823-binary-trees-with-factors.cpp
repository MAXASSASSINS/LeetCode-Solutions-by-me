class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int mod = 1e9 + 7;
        
        unordered_map<int,int> m;
        
        for(int i = 0; i < arr.size(); i++){
            m[arr[i]] = 1;
            
            int j = 0, k = i - 1;
            
            while(j <= k){
                long long prod = 1LL * arr[j] * arr[k];
                int tar = arr[i];
                if(prod < tar){
                    j++;
                }
                else if(prod > tar){
                    k--;
                }
                else{
                    long long ways = (1LL * m[arr[j]] * m[arr[k]]) % mod;
                    if(j != k){
                        ways = (ways * 2) % mod;                        
                    }
                    m[arr[i]] = (m[arr[i]] + ways) % mod;
                    j++;
                    k--;
                }
            }
        }
        
        auto it = m.begin();
        
        int res = 0;
        while(it != m.end()){
            res = (res + it->second) % mod;
            it++;
        }
        
        
        return res;
    }
};