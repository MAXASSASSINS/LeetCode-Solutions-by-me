class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for (int i = 0; i <= n; ++i) {
            int count = 0;
            int temp = i;
            while(temp > 0){
                if(temp % 2 == 0){
                    temp /= 2;
                }
                else{
                    temp -= 1;
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};