//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(vector<vector<int>> &m, vector<vector<bool>> &isVisited, vector<string> &ans, 
        const int &n, string &t, int row, int col){
            
        if(row == n - 1 && col == n - 1){
            ans.push_back(t);
            return;
        }
        // down
        if(row + 1 < n && m[row + 1][col] == 1 && !isVisited[row + 1][col]){
            t += 'D';
            isVisited[row + 1][col] = true;
            solve(m, isVisited, ans, n, t, row + 1, col);
            t.pop_back();
            isVisited[row + 1][col] = false;
        }
        
        // left
        if(col - 1 >= 0 && m[row][col - 1] == 1 && !isVisited[row][col - 1]){
            t += 'L';
            isVisited[row][col - 1] = true;
            solve(m, isVisited, ans, n, t, row, col - 1);
            t.pop_back();
            isVisited[row][col - 1] = false;
        }

        // right
        if(col + 1 < n && m[row][col + 1] == 1 && !isVisited[row][col + 1]){
            t += 'R';
            isVisited[row][col + 1] = true;
            solve(m, isVisited, ans, n, t, row, col + 1);
            t.pop_back();
            isVisited[row][col + 1] = false;
        }

        // up
        if(row - 1 >= 0 && m[row - 1][col] == 1 && !isVisited[row - 1][col]){
            t += 'U';
            isVisited[row - 1][col] = true;
            solve(m, isVisited, ans, n, t, row - 1, col);
            t.pop_back();
            isVisited[row - 1][col] = false;
        }

        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        if(m[0][0] == 0) return ans;
        
        vector<vector<bool>> isVisited(n , vector<bool> (n));
        isVisited[0][0] = true;
        string t;
        solve(m, isVisited, ans, n, t, 0, 0);
        return ans;
        
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends