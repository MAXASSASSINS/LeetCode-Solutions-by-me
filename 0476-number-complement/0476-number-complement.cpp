class Solution {
public:
    int findComplement(int num) {
        vector<int> vec;
        
        while(num > 0){
            vec.push_back(num % 2);
            num /= 2;
        }
        
        reverse(vec.begin(), vec.end());
        
        for(int &bit: vec){
            bit = !bit;
        }
        
        int ans = 0;
        for(int i = 0; i < vec.size(); i++){
            ans *= 2;
            ans += vec[i];
        }
        
        return ans;
        
        
    }
};