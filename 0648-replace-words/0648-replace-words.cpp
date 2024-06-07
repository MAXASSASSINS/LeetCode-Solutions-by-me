class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ans;
        
        sort(dictionary.begin(), dictionary.end());
        
        for(int i = 0; i < sentence.length(); i++){
            string word;
            while(i < sentence.length() && sentence[i] != ' '){
                word += sentence[i];
                i++;
            }
            
            bool rootFound = false;
            for(int j = 0; j < dictionary.size(); j++){
                string root = dictionary[j];
                int len = root.length();
                if(len > word.length()) continue;
                if(root == word.substr(0, len)){
                    // cout<<root<<"\t";
                    ans += root + ' ';
                    rootFound = true;
                    break;
                }
            }
            
            if(!rootFound) ans += word + ' ';
        }
        
        ans.pop_back();
        
        return ans;
        
        
    }
};