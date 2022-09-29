class Solution {
public:

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        auto it = lower_bound(arr.begin(), arr.end(), x);
        int index = it - arr.begin();

        if (index > 0 && index < arr.size() && abs(arr[index] - x)  >= abs(arr[index - 1] - x)){
          index -= 1;
            while (index > 0 && arr[index]  == arr[index - 1]){
                index--;
            }
        }
        if (index < arr.size()){
            ans.push_back(arr[index]);
            k--;
        }
        int st = index - 1;
        int en = index + 1;
        if (st < 0){
            st += 2;
            while (k > 0){
                ans.push_back(arr[st]);
                st++;
                k--;
            }
            sort(ans.begin(), ans.end());
            return ans;
        }
        if(en > arr.size()){
            en -= 2;
            while (k > 0){
                ans.push_back(arr[en]);
                en--;
                k--;
            }
            sort(ans.begin(), ans.end());
            return ans;
        }


        while (st >= 0 && en < arr.size() && k > 0){
            int a = arr[st];
            int b = arr[en];
            int diffA = abs(a - x);
            int diffB = abs(b - x);
            if (diffA == diffB){
                if (a < b){
                    ans.push_back(a);
                    st--;
                }
                else{
                    ans.push_back(b);
                    en++;
                }

            }
            else if (diffA < diffB){
                ans.push_back(a);
                st--;
            }
            else{
                ans.push_back(b);
                en++;
            }
            k--;
        }

        while (st < 0 && k > 0){
            ans.push_back(arr[en]);
            en++;
            k--;
        }
        while (en >= arr.size() && k > 0){
            ans.push_back(arr[st]);
            st--;
            k--;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};