class Solution {
public:
    int solve(int n, int count, int copied){
        if(count == n) return 0;
        if(count > n) return 1e9; 
        
        int pasteNew = 2 + solve(n, count + count, count);
        int pasteOld = INT_MAX;
        if(copied != -1){
            pasteOld = 1 + solve(n, count + copied, copied);
        }
        
        return min(pasteOld, pasteNew);
    }
    int minSteps(int n) {
        if(n == 1) return 0;
        return solve(n, 1, -1);
        // return 0;
    }
}; 