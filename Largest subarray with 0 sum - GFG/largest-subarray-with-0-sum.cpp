//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&arr, int n)
    {   
        map<int,int> m;
        int ans = 0;
        int currSum = 0;
        for(int i = 0;i < arr.size(); i++){
            currSum += arr[i];
            auto it = m.find(currSum);
            if(currSum == 0){
                ans = max(ans, i + 1);
                continue;
            }
            if(it != m.end()){
                ans = max(ans, i - it->second);
            }
            else{
                m.insert({currSum, i});
            }
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
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends