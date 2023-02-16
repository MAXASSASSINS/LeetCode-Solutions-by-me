//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    pair<int,int> ans = {-1, -1};
    int maxVal = INT_MIN;
    for(int i = 0; i < n; i++){
        if(arr[i] > maxVal && arr[i] <= x){
            ans.first = arr[i];
            maxVal = arr[i];
        }
    }
    
    
    int ceil = INT_MAX;
    for(int i = 0; i < n; i++){
        if(arr[i] < ceil && arr[i] >= x){
            ans.second = arr[i];
            ceil = arr[i];
        }
    }
    
    return ans;
    
    
    
}