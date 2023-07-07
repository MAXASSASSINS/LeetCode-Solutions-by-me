class Solution {
public:
    int findMaxCount(string s, int k, char c){
        int j = 0;
        int ans = 0;
        
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] != c){
                k--;
            }
            while(k < 0 && s[j] == c){
                j++;
            }
            if(k < 0){
                j++;
                k++;
            }
            ans = max(ans, i - j + 1);

        }
        
        return ans;
    }
    
    int maxConsecutiveAnswers(string answerKey, int k) {
        int t_s = findMaxCount(answerKey, k, 'T');
        int f_s = findMaxCount(answerKey, k, 'F');
        cout<<t_s<<endl;
        return max(t_s, f_s);
        
    }
};