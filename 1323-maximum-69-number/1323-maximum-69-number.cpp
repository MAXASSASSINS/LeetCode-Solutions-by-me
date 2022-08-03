class Solution {
public:
    int maximum69Number (int num) {
        vector<int> arr;
        while (num != 0){
            arr.push_back(num % 10);
            num /= 10;
        }
        for (int i = arr.size() -1; i >= 0 ; --i) {
            if(arr[i] == 6){
                arr[i] = 9;
                break;
            }
        }
        int ans = 0;
        for (int i = arr.size() - 1; i >= 0; --i) {
            ans *= 10;
            ans += arr[i];
        }
        return ans;
    }
};