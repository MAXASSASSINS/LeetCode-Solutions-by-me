class Solution {
public:
    int kthGrammar(int n, int k) {
        vector<int> path;
        path.push_back(k);
        
        string zero = "01";
        string one = "10";
        
        int temp = n;
        
        while(temp > 0){
            if(k % 2){
                k /= 2;
                k += 1;
            }
            else{
                k /= 2;
            }
            path.push_back(k);
            temp--;
        }
        int ans = 0;
        for(int i = n - 2; i >= 0; i--){
            if(ans == 0){
                if(path[i] % 2 == 1){
                    ans = 0;
                }
                else{
                    ans = 1;
                }
            }
            else{
                if(path[i] % 2 == 1){
                    ans = 1;
                }
                else{
                    ans = 0;
                }
            }
        }
        return ans;
    }
    
};