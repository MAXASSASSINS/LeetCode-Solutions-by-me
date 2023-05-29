//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void bitManipulation(int num, int i) {
        int n = 1 << (i - 1);
        int ans1 = num >> (i - 1) & 1;
        
        int ans2 = num | n;
        
        n = ~n;
        
        int ans3 = num & n;
        
        cout<<ans1<<" "<<ans2<<" "<<ans3;
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends