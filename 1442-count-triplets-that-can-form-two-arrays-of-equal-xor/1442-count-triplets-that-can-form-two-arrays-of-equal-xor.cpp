class Solution {
public:
    int countTriplets(vector<int>& arr) {
        cout<<arr.size();
        int n = arr.size();
        int cnt = 0;
        for(int i = 0; i < n; i++){       
            for(int j = i + 1; j < n; j++){
                int a = 0;
                for(int l = i; l < j; l++){
                    a ^= arr[l];
                }
                int b = 0;
                int k = j;
                while(k < n){
                    b ^= arr[k];
                    k++;
                    
                    if(a == b){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};