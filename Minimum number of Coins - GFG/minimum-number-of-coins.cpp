//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        int arr[] = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
        // code here
        int i = 0;
        vector<int> ans;
        
        while(N > 0){
            int coins = N / arr[i];
            for(int j = 0; j < coins; j++){
                ans.push_back(arr[i]);
            }
            N %= arr[i];
            i++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends