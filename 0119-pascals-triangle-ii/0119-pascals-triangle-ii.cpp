class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1);
        
        res[0] = 1;
        
        int m = rowIndex;
        int n = 1;
        
        for(int i = 1; i < rowIndex + 1; i++){
            long long temp = (1LL * res[i - 1] * m)/n;
            // res[i] = (res[i - 1] * m)/n;
            res[i] = temp;
            m--;
            n++;
        }
        
        return res;
    }
};