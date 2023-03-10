class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        unordered_map<string, int> umap;
        umap["I"] = 1;
        umap["IV"] = 4;
        umap["V"] = 5;
        umap["IX"] = 9;
        umap["X"] = 10;
        umap["XL"] = 40;
        umap["L"] = 50;
        umap["XC"] = 90;
        umap["C"] = 100;
        umap["CD"] = 400;
        umap["D"] = 500;
        umap["CM"] = 900;
        umap["M"] = 1000;

        int i = 0;
        for (; i < s.length() - 1; ++i) {
            string s1,s2;
            s1 = s.at(i);
            s2 = s.at(i + 1);
            if(umap[s1] >= umap[s2]){
                result += umap[s1];
            }
            else{
                string s3 = s1 + s2;
                result += umap[s3];
                i++;
            }
        }
        if(i < s.length()){
            string temp;
            temp = s.at(i);
            result += umap[temp];
        }
        return result;
    }
};