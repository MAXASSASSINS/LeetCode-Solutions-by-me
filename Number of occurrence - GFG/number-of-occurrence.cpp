//{ Driver Code Starts

#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int nums[], int n, int target) {
	    int l = 0;
        int h = n - 1;
        vector<int> ans = {-1, -1};
        while(l <= h){
            int mid = l + (h - l)/2;
            if(nums[mid] < target){
                l = mid + 1;
            }
            else if(nums[mid] > target){
                h = mid - 1;
            }
            else{
                h = mid - 1;
                ans[0] = mid;
            }
        }
        
        l = 0;
        h = n - 1;
        while(l <= h){
            int mid = l + (h - l)/2;
            if(nums[mid] < target){
                l = mid + 1;
            }
            else if(nums[mid] > target){
                h = mid - 1;
            }
            else{
                l = mid + 1;
                ans[1] = mid;
            }
        }
        if(ans[0] == -1) return 0;
        return ans[1] - ans[0] + 1;
	}
};

//{ Driver Code Starts.

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
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends