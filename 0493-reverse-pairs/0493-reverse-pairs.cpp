class Solution {
public:
    void merge(vector<int> &arr, int s, int m, int e, int &cnt){
        int l = m + 1;
        for(int i = s; i <= m; i++){
            while(l <= e && arr[i] > 2LL * arr[l]){
                l++;
            }
            cnt += l - (m + 1);
        }
        int temp[e - s + 1];
        
        int  i = s,  j = m + 1;
        int k = 0;
        while(i <= m && j <= e){
            if(arr[i] <= arr[j]){
                temp[k++] = arr[i++];
            }
            else{
                temp[k++] = arr[j++];
            }
        }
        
        while(i <= m){
            temp[k++] = arr[i++];
        }
        
        while(j <= e){
            temp[k++] = arr[j++];
        }
        
        for(int idx = s; idx <= e; idx++){
            arr[idx] = temp[idx - s];
        }
    }
    
    void mergeSort(vector<int> &arr, int s, int e, int &cnt){
        if(s >= e) return;
        
        int m = s + (e - s)/2;
        mergeSort(arr, s, m, cnt);
        mergeSort(arr, m + 1, e, cnt);
        
        merge(arr, s, m, e, cnt);
        
    }
    int reversePairs(vector<int>& nums) {
        int ans = 0;
        mergeSort(nums, 0, nums.size() - 1, ans);
        return ans;
    }
};