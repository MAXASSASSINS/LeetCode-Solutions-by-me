class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> prime = {2,3,5};
        vector<int> temp = {1};
        int c2 = 0;
        int c3 = 0;
        int c5 = 0;
        while(temp.size() <= n){
            int num = (min(2 * temp[c2], min(3 * temp[c3], 5 * temp[c5])));
            if(num == 2 * temp[c2])
                c2++;
            if(num == 3 * temp[c3])
                c3++;
            if(num == 5 * temp[c5])
                c5++;
            temp.push_back(num);
        }
        
        return temp[n - 1];
        
    }
};