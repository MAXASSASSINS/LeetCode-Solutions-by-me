//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    void merge(long long arr[], long long s, long long m, long long e, long long &cnt){
        long long temp[e - s + 1];
        
        long long  i = s,  j = m;
        long long k = 0;
        while(i < m && j <= e){
            if(arr[i] <= arr[j]){
                temp[k++] = arr[i++];
            }
            else{
                temp[k++] = arr[j++];
                cnt += m - i;
            }
        }
        
        while(i < m){
            temp[k++] = arr[i++];
        }
        
        while(j <= e){
            temp[k++] = arr[j++];
        }
        
        for(int idx = s; idx <= e; idx++){
            arr[idx] = temp[idx - s];
        }
    }
    
    void mergeSort(long long arr[], long long s, long long e, long long int &cnt){
        if(s >= e) return;
        
        int m = s + (e - s)/2;
        mergeSort(arr, s, m, cnt);
        mergeSort(arr, m + 1, e, cnt);
        
        merge(arr, s, m + 1, e, cnt);
        
    }
    long long int inversionCount(long long arr[], long long N)
    {
        long long int ans = 0;
        mergeSort(arr, 0, N - 1, ans);
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends