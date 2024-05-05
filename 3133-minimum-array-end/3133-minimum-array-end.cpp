class Solution {
public:
    vector<int> decToBin(int n){
        vector<int> res(64);
        int i = 0;
        while(n > 0){
            res[i] = n % 2;
            n /= 2;
            i++;
        }
        
        return res;
    }
    
    long long binToDec(vector<int> &vec){
        long long ans = 0;
        for(int i = 0; i < vec.size(); i++){
            ans += vec[i] * pow(2, i);
        }
        
        return ans;
    }
    
    long long minEnd(int n, int x) {
        vector<int> xBin = decToBin(x);    
        vector<int> n1Bin = decToBin(n - 1);
        
//         for(auto x: xBin){
//             cout<<x<<" ";
//         }
//         cout<<endl;
        
//         for(auto x: n1Bin){
//             cout<<x<<" ";
//         }
        
        int j = 0;
        for(int i = 0; i < xBin.size(); i++){
            if(xBin[i] == 1) continue;
            xBin[i] = n1Bin[j];
            j++;
        }
        
        return binToDec(xBin);
        
    }
};