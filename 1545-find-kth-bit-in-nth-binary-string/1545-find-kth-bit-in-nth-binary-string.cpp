class Solution {
public:
    char findKthBit(int n, int k) {
        string prev = "0";
        string revInv = "1";
        
        if(n == 1) return '0';
        
        for(int i = 2; i <= n; i++){
            string curr = prev + "1" + revInv;
            string temp;
            for(auto c: curr){
                if(c == '0') temp += '1';
                else temp += '0';
            }
            
            reverse(temp.begin(), temp.end());
            
            revInv = temp;
            prev = curr;
            if(i == n){
                // cout<<curr<<endl;
                return curr[k - 1];
            }
        }
        
        return '\0';
    }
};