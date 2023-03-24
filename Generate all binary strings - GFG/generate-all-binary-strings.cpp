//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void solve(string s, int index, set<string> &st){
        if(index >= s.length()) return;
        
        // leave current index value to 0
        solve(s, index + 1, st);
        
        // change the current index value to 1
        s[index] = '1';
        solve(s, index + 2, st);
        
        st.insert(s);
    }
    void generateBinaryStrings(int num){
        string t;
        for(int i = 0; i < num; i++){
            t += '0';
        }
        int ans = 0;
        set<string> st;

        st.insert(t);
        solve(t, 0, st);
        for(auto it: st){
            cout<<it<<" ";
        }
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        obj.generateBinaryStrings(n);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends