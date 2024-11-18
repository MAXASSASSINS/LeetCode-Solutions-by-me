class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> sums(2 * n, 0);
        int sum = 0;
        for(int i = 0; i < 2 * n; i++){
            sum += code[i % n];
            sums[i] = sum;
        }
        
        vector<int> res(n);
        for(int i = 0; i < n; i++){
            if(k > 0){
                int sum = sums[i + k] - sums[i];
                res[i] = sum;
            }
            else if(k < 0){
                int sum = sums[i + n - 1] - sums[i + n - 1 + k];
                res[i] = sum;
            }
            else{
                res[i] = 0;
            }
        }
        
        return res;
        
    }
};