class Solution {
public:
    int compareVersion(string version1, string version2) {
        int len1 = version1.length();
        int len2 = version2.length(); 
        
        int i = 0;
        int j = 0;
        
        while(i < len1 || j < len2){
            string t1, t2;
            while(i < len1 && version1[i] != '.'){
                t1 += version1[i];
                i++;
            }
            while(j < len2 && version2[j] != '.'){
                t2 += version2[j];
                j++;
            }
            if(t1.length() == 0) t1 = "0";
            if(t2.length() == 0) t2 = "0";
            int v1, v2;
            v1 = stoi(t1);
            v2 = stoi(t2);
            if(v1 > v2) return 1;
            if(v1 < v2) return -1;
            i++;
            j++;
        }
        
        return 0;
    }
};