
class Solution {
public:
    
    bool isValid(int row, int col, int n, int m){
        if(row < n && col < m && row > -1 && col > -1) return true;
        return false;
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        
        vector<vector<int>> ans(rows, vector<int>(cols, INT_MAX));
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        ans[0][0] = 0;
        pq.push({0, 0, 0});
        
        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, -1, 0, 1};
        
        while(!pq.empty()){
            auto vec = pq.top();
            pq.pop();
            
            int row = vec[0];
            int col = vec[1];
            int diff = vec[2];
            
            if(row == rows - 1 && col == cols - 1) return diff;
            
            for(int i = 0; i < 4; i++){
                int newRow = row + drow[i];
                int newCol = col + dcol[i];
                
                if(isValid(newRow, newCol, rows, cols)){
                    int newEffort = max(abs(heights[row][col] - heights[newRow][newCol]), diff);
                    if(ans[newRow][newCol] > diff){
                        ans[newRow][newCol] = newEffort;
                        pq.push({newRow, newCol, newEffort});
                    }
                        
                }
            }
        }
        
        return 0;
    }
};