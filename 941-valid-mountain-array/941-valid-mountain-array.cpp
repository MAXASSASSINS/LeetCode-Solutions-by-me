class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() <= 2){
            return false;
        }
        int maxElement = -1;
        int maxIndex = -1;
        for (int i = 0; i < arr.size() - 1; ++i) {
            if(arr[i] == arr[i + 1]){
                return false;
            }
            if(arr[i] > maxElement){
                maxElement = arr[i];
                maxIndex = i;
            }
        }
        if(maxIndex == 0 || maxIndex == arr.size() - 1){
            return false;
        }
        for (int i = 0; i < maxIndex; ++i) {
            if(arr[i] > arr[i + 1]){
                return false;
            }
        }
        for (int i = maxIndex; i < arr.size() - 1; ++i) {
            if(arr[i] < arr[i + 1]){
                return false;
            }
        }
        return true;
    }
};