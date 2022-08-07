class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> arr = {1,1,1,1,1};
        int i = 0;
        while (i < n) {
            int j = 0;
            while (j < arr.size()){
                int sum = 0;
                for (int k = j; k < arr.size(); ++k) {
                    sum += arr[k];
                }
                arr[j] = sum;
                j++;
            }
            i++;
        }
        return arr[0];
    }
};