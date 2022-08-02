class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int initialSize = arr.size();
        int i = 0;
        while (i < arr.size()) {
            if(arr[i] == 0){
                arr.insert(arr.begin() + i + 1, 0);
                i++;
            }
            i++;
        }
        arr.resize(initialSize);
    }
};