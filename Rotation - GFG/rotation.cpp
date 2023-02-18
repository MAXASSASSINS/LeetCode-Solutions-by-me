//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    int findPivot(int nums[], int low, int high, int n) {
        if(high < low){
            return -1;
        }
        int mid = (low + high) / 2;
        if (mid + 1 < n && nums[mid] > nums[mid + 1]) {
            return mid;
        } else if (mid - 1 > 0 && nums[mid] < nums[mid - 1]) {
            return mid - 1;
        } else if(nums[low] > nums[mid]){
            return findPivot(nums, low, mid - 1, n);
        }
        else if(nums[mid] > nums[high]){
            return findPivot(nums, mid + 1, high, n);
        }
        return -1;
    }
	int findKRotation(int arr[], int n) {
	    // code here
	    int ans = findPivot(arr, 0, n - 1, n);
	    return ans + 1;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends