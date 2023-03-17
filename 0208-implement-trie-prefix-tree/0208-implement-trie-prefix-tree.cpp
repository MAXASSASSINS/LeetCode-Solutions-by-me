class TrieNode{
public:
    TrieNode *children[27];
    char data;
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i = 0; i < 27; i++){
            children[i] = nullptr;
        }
        isTerminal = false;
    }
};


class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode('\0');
    } 

    
    void insert(string word) {
        insertUtil(root, word);
    }
    
    bool search(string word) {
        return searchUtil(root, word);
    }
    
    bool startsWith(string prefix) {
        return startsWithUtil(root, prefix);
    }

    void insertUtil(TrieNode *root, string word){
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }
        
        int index = word[0] - 'a';

        TrieNode *child;
        if(root->children[index] != nullptr){
            child = root->children[index];
        }else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    bool searchUtil(TrieNode *root, string word){
        if(word.length() == 0){
            return root->isTerminal;
        }

        int index = word[0] - 'a';

        TrieNode *child;  
        if(root->children[index] != nullptr){
            child = root->children[index];
        }else{
            return false;
        }

        return searchUtil(child, word.substr(1));

    }

    bool startsWithUtil(TrieNode *root, string word){
        if(word.length() == 0){
            return true;
        }

        int index = word[0] - 'a';

        TrieNode *child;  
        if(root->children[index] != nullptr){
            child = root->children[index];
        }else{
            return false;
        }

        return startsWithUtil(child, word.substr(1)); 
    }

    
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */