//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    bool possible(int A[], int N, int M, int mid){
        int cnt = 1;
        int temp = 0;
        for(int i = 0; i < N; i++){
            if(A[i] > mid) return false;
            if(temp + A[i] > mid){
                cnt++;
                temp = A[i];
            }
            else{
                temp += A[i];
            }
        }
        
        return cnt <= M;
    }
    
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        if(N < M) return -1;
        int mini = INT_MAX;
        int total = 0;
        for(int i = 0; i < N; i++){
            total += A[i];
            mini = min(mini, A[i]);
        }
        
        int low = mini;
        int high = total;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            if(possible(A, N, M, mid)) high = mid - 1;
            else low = mid + 1;
        }
        
        return low;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends