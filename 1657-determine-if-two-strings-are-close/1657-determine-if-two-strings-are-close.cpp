class Solution {
public:
    bool closeStrings(string word1, string word2) 
    {
        
        if(word1.size()!=word2.size())
            return false;
        
        // if size is same;
        
        unordered_map<char,int> um1,um2;
        
        for(auto ch: word1)
            um1[ch]++;
        
        for(auto ch: word2)
            um2[ch]++;
        
         if(um1.size()!= um2.size())
            return false;
        
        if(um1==um2)
            return true;
        else
        {
            for(auto ch: um1)
                if(um2[ch.first]==0)
                    return false;
            
            for(auto ch: um2)
                if(um1[ch.first]==0)
                    return false;
            
            vector<int> v1, v2;
            
                for(auto ch: um1)
                v1.push_back(ch.second);
            
                for(auto ch: um2)
                v2.push_back(ch.second);
            
                sort(v1.begin(),v1.end());
                sort(v2.begin(),v2.end());
            
            if(v1==v2)
                return true;
            else
                return false;
        }
        
        return true;
        
    }
};