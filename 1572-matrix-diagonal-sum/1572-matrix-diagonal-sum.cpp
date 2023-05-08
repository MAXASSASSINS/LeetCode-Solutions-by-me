class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int i = 0, j = 0;
        int leftSum = 0, rightSum = 0;
        
        while(i < n){
            leftSum += mat[i][i];
            i++;
        }
        
        i = 0; 
        j = n - 1;
        while(j >= 0){
            rightSum += mat[i][j];
            i++;
            j--;
        }
        
        if(n % 2 == 1){
            int num = mat[n / 2][n / 2];
            return leftSum + rightSum - num;
        }
        
        
        return leftSum + rightSum;
        
        
    }
};