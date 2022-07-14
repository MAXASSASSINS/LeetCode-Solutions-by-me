class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> arr(26,0);
        for (int i = 0; i < ransomNote.length(); ++i) {
            int val = ransomNote[i] - 'a';
            arr[val]++;
        }
        for (int i = 0; i < magazine.length(); ++i) {
            int val = magazine[i] - 'a';
            if(arr[val] > 0){
                arr[val]--;
            }
        }
        for (int i = 0; i < 26; ++i) {
            if(arr[i] != 0)
                return false;
        }
        return true;
    }
};