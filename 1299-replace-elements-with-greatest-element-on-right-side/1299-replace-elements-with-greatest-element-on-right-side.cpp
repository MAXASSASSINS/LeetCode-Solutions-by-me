class Solution {
public:
    void findMax(vector<int> &arr, int left, int &maxElement, int &maxIndex){
        for (int i = left; i < arr.size(); ++i) {
            if(arr[i] > maxElement){
                maxElement = arr[i];
                maxIndex = i;
            }
        }
    }

    vector<int> replaceElements(vector<int>& arr) {
        int maxElement = INT_MIN;
        int maxIndex = -1;
        int i = 0;
        int left = i;
        while(i < arr.size()){
            findMax(arr, left, maxElement, maxIndex);
            while (i < maxIndex){
                arr[i] = maxElement;
                i++;
            }
            left = i + 1;
            if(left == arr.size()){
                break;
            }
            maxElement = INT_MIN;
            maxIndex = -1;
        }
        arr[arr.size() - 1] = -1;
        return arr;
    }
};