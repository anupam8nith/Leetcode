
class Trie {
    
private:
    
    struct TrieNode
    {
        struct TrieNode *child[26];
        bool endofword;
    };
    TrieNode* node;    

public:
    Trie() 
    {
     node = new TrieNode();
    }
    
    void insert(string word) 
    {
        TrieNode *curr= node;
        
        for(auto temp: word)
        {
            if(curr->child[temp-'a']==NULL) curr->child[temp-'a'] = new TrieNode();
            curr=curr->child[temp-'a'];
        }
        
        curr->endofword=true;
    }
    
    bool search(string word) 
    {
        TrieNode *curr=node;
        
        for(char temp: word)
        {
            if(curr->child[temp-'a']==NULL) return false;
            curr= curr->child[temp-'a'];
        }
        
        if(curr->endofword==true) return true;
            
        return false;
    }
    
    bool startsWith(string prefix) 
    {
        TrieNode *curr = node;
        
        for(char ch: prefix)
        {
            if(curr->child[ch-'a']==NULL) return false;
            curr= curr->child[ch-'a'];
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