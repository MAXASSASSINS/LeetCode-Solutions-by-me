//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool possible(vector<int>& nums, int k, double mid){
        int cnt = 0;
        for(int i = 1; i < nums.size(); i++){
            cnt += (nums[i] - nums[i - 1])/mid;
        }
        
        return cnt <= k;
    }
    double findSmallestMaxDist(vector<int> &stations, int K){
        int n = stations.size();
        int maxDis = stations[n - 1] - stations[0];
        
        double l = 0;
        double h = maxDis;
        
        while(h - l > 1e-6){
            double mid = l + (h - l)/2.0;
            
            if(possible(stations, K, mid)){
                h = mid;
            }
            else{
                l = mid;
            }
        }
        
        return h;
        
    }
};

//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> stations(n);
    for (int i = 0; i < n; i++)
    {
      cin >> stations[i];
    }
    int k;
    cin >> k;
    Solution obj;
    cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k) << endl;
  }
  return 0;
}
// } Driver Code Ends