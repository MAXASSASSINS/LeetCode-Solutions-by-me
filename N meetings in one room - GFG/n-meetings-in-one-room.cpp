//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    bool static cmp(pair<int,int> a, pair<int,int> b){
        if(a.first < b.first) return true;
        else if(a.first == b.first) return a.second < b.second;
        return false;
    }
    
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int, int>> vec;
        
        for(int i = 0; i < n; i++){
            vec.push_back({end[i], start[i]});
        }
        
        sort(vec.begin(), vec.end(), cmp);
        
        
        int count = 0;
        int prevEnd = -1;
        for(auto it : vec){
            if(it.second > prevEnd){
                count++;
                prevEnd = it.first;
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends