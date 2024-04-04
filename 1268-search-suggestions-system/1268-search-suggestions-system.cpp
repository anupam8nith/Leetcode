class Solution {
public:
    
     struct Trie {
        unordered_map<char, Trie*> leaves;
        // Lexographically sorted suggestion till each char 
        vector<string> suggestions;
    };
    
    void insertTrie(Trie* root, string word) {
        for(const char& c: word) {
            if(root->leaves.find(c) == root->leaves.end())
                root->leaves[c] = new Trie();
            root = root->leaves[c];
            
            // Add the current word as suggestion if we dont have enough suggestions
            if(root->suggestions.size() < 3)
                root->suggestions.emplace_back(word);
        }
    }
    
    
    vector<vector<string>> suggestionTrie(vector<string>& products, string searchWord) {
        vector<vector<string>> result(searchWord.size());
        // sort the words 
        sort(begin(products), end(products));
        // Create the Trie, since the words are sorted
        // so the suggestions are also lexographically sorted
        Trie *root = new Trie();
        for(const string &word: products)
            insertTrie(root, word);
        
        string prefix;
        for(int i = 0; i < searchWord.size(); i++) {
            auto it = root->leaves.find(searchWord[i]);
            if(it != root->leaves.end()) {
                root = it->second;
            }
            else
                break;
            // add suggestions if any for the current char
            result[i] = root->suggestions;
        }
        return result;
    }
    
    
     vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        // return suggesteBinarySearch(products, searchWord);
        return suggestionTrie(products, searchWord);
    }
};



// class Solution {
// public:
    
//     struct TrieNode
//     {
//         TrieNode *link[26];
//         bool endofword;
//     };
//     TrieNode *node = new TrieNode();
    
//     void insert(string &word)
//     {
//         TrieNode *curr = node;
        
//         for(char ch: word)
//         {
//             if(!curr->link[ch-'a'])curr->link[ch-'a'] = new TrieNode();
//             curr = curr->link[ch-'a'];
//         }
//         curr->endofword=true;
        
//     }
    
//     vector<string> startsWith(string& prefix)
//     {
//         TrieNode *curr = node;
//         vector<string> found;
        
//         for(char ch: prefix)
//         {
//             if(!curr->link[ch-'a']) return found;
//             curr = curr->link[ch-'a'];
//         }
        
        
//         while(curr && found.size()!=3)
//         {
//             string temp = prefix;
//             for(char ch = 'a';ch<='z';ch++)
//             {
//                 if(curr->endofword=true)
//                 {
//                     temp+=ch;
//                 }
//             }
            
//         }
        
//     }
    
    
//     vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
//     {
        
//     }
// };