//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int N){
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        
        
        map<int,int> m;
        
        int rank = 1;
        
        for(int i = 0; i < N; i++){
            if(m.find(temp[i]) == m.end()){
                m[temp[i]] = rank++;
            }
        }
        
        for(int i = 0; i < N; i++){
            temp[i] = m[arr[i]];
        }
        
        return temp;
    }

};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends