class Trie {
    
private:
    struct TrieNode
    {
        TrieNode *link[26];
        bool endofword;      
    };
    TrieNode *node;
    
public:
    Trie() {
        node = new TrieNode();
    }
    
    void insert(string word) 
    {
        TrieNode *curr = node;
        
        for(char ch: word)
        {
            if(!curr->link[ch-'a'])curr->link[ch-'a'] = new TrieNode();
            curr = curr->link[ch-'a'];
        }
        
        curr->endofword= true;
    }
    
    bool search(string word) 
    {
        TrieNode *curr = node;
        
        for(char ch: word)
        {
            if(!curr->link[ch-'a']) return false;
            curr = curr->link[ch-'a'];
        }
        
        
        if(curr->endofword==true) return true;
        
        return false;
        
    }
    
    bool startsWith(string prefix) 
    {
        TrieNode *curr = node;
        
        for(char ch: prefix)
        {
            if(!curr->link[ch-'a']) return false;
            curr = curr->link[ch-'a'];
        }
             
       return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */