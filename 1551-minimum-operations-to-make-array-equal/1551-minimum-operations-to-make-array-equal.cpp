class Solution {
public:
    int minOperations(int n) {
        if(n % 2 == 0){
            return (int)pow(n/2, 2);
        }
        int num = n /2;
        return num * (num + 1);
    }
};