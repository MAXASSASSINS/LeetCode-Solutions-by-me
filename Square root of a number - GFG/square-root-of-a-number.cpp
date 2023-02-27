//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here
        long long int l = 1;
        long long int h = x;
        while(l <= h ){
            long long int mid = l + (h - l)/2;
            if(mid == x / mid) return mid;
            else if(mid > x/mid){
                h = mid - 1;
            }
            else l = mid + 1;
        }
        
        return h;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends