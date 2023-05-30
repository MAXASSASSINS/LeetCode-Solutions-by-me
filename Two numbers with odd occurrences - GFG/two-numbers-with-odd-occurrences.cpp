//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int arr[], long long int n)  
    {
        vector<long long int> ans(2);
        long long int xor2 = 0;
        for(int i = 0; i < n; i++){
            xor2 ^= arr[i];
        }

        int num = xor2;
        int count = 0;
        while((num & 1) == 0){
            num = num >> 1;
            count++;
        }
        
       
        
        for(int i = 0; i < n; i++){
            if(arr[i] & (1 << count)){
                ans[0] ^= arr[i];
            }
            else{
                ans[1] ^= arr[i];
            }
        }
        
        if(ans[0] < ans[1]){
            swap(ans[0], ans[1]);
        }
        
        return ans;
        
        
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends