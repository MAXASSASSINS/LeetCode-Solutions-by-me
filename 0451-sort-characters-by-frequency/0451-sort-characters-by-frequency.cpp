class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char , int> lower;
        unordered_map<char , int> upper;
        for(int i = 0; i < s.length(); i++){
            char c = s.at(i);
            if(islower(c)){
                lower[c]++;
            }
            else{
                upper[c]++;
            }
        }
        multimap<int , char, greater<int>> m1;
        auto it = lower.begin();

        while (it != lower.end()){
            m1.insert(make_pair(it->second, it->first));
            it++;
        }
        it = upper.begin();
        while (it != upper.end()){
            m1.insert(make_pair(it->second, it->first));
            it++;
        }
        string t;
        auto it2 = m1.begin();
        while (it2 != m1.end()){
            for(int i = 0; i < it2->first; i++){
                t += it2->second;
            }
            it2++;
        }
        return t;

    }
};