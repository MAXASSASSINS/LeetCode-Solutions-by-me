class Solution {
public:
    int countVowelPermutation(int n) {
        if(n == 1) return 5;
        
        int mod = 1e9 + 7;
        
        unordered_map<char, unordered_set<char>> rules;
        
        rules['a'] = {'e'};
        rules['e'] = {'a', 'i'};
        rules['i'] = {'a', 'e', 'o', 'u'};
        rules['o'] = {'i', 'u'};
        rules['u'] = {'a'};
        
        
        unordered_map<char, int> curr, next;
        curr['a'] = 1;
        curr['e'] = 1;
        curr['i'] = 1;
        curr['o'] = 1;
        curr['u'] = 1;
        
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        
        int total = 0;        
        for(int i = 2; i <= n; i++){
            total = 0;
            for(int j = 0; j < 5; j++){
                char c = vowels[j];
                int cnt = curr[c];
                auto rule = rules[c];
                total += (cnt * rule.size()) % mod;
                total %= mod;
                for(auto it = rule.begin(); it != rule.end(); it++){
                    char x = *it;
                    next[x] = (next[x] % mod + cnt % mod) % mod;
                }
            }
            curr = next;
            next.clear();
            
        }
        
        
        return total % mod;
    }
};