class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> ans;
        for (int i = 0; i < emails.size(); ++i) {
            int j = 0;
            bool plusFound = false;
            string temp;
            while(emails[i][j] != '@'){
                if (emails[i][j] == '+'){
                    plusFound = true;
                    break;
                }
                else if(emails[i][j] != '.'){
                    temp += emails[i][j];
                }
                j++;
            }
            if (plusFound){
                while (emails[i][j] != '@'){
                    j++;
                }
            }
            while(j < emails[i].size()){
                temp += emails[i][j];
                j++;
            }
            ans.insert(temp);
        }
        return ans.size();
    }
};