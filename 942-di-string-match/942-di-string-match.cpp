class Solution {
public:
    vector<int> diStringMatch(string S) {
        
        int n = S.size(), l = 0, r = n;
        
        vector<int> res(n+1, 0);
        for(int i = 0; i < n; i++){
            switch(S[i]){
                case 'I':  //meet increase : assign current smallest value to guarantee next value is larger.  
                    res[i] = l++;
                    break;
                case 'D': //meet decrease : assign current largest value to guarantee next value is smaller.
                    res[i] = r--;
                    break;
            }
        }
		// At this point, l == r ，only one value is not assigned yet.
        res[n] = l;
        return res;
    }
};