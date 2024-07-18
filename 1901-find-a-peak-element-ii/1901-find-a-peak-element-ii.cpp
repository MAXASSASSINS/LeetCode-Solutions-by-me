class Solution {
public:
    int getMaxIndex(vector<vector<int>> &mat, int col){
        int maxi = 0;
        for(int i = 1; i < mat.size(); i++){
            if(mat[maxi][col] < mat[i][col]){
                maxi = i;
            }
        }
        
        return maxi;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        int low = 0;
        int high = n - 1;
        
        while(low <= high){
            int mid = (low + high) / 2;
            int maxRow = getMaxIndex(mat, mid);
            cout<<maxRow<<endl;
            
            int curr = mat[maxRow][mid];
            int left = mid - 1 >= 0 ? mat[maxRow][mid - 1] : -1;
            int right = mid + 1 < n ? mat[maxRow][mid + 1] : -1;
            
            if(curr > left && curr > right){
                return {maxRow, mid};
            }
            else if(left > curr){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return {-1, -1};
    }
};