//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int maxi = 0;
	    int maxRow = 0;
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < m; j++){
	            if(arr[i][j] == 1){
	                if(maxi < m - j){
	                    maxi = m - j;    
	                    maxRow = i;
	                } 
	                break;
	            }
	        }
	    }
	    if(maxi == 0) return -1;
	    
	    return maxRow;
	    
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends