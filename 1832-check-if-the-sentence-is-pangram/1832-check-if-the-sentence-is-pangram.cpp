class Solution {
public:
    bool checkIfPangram(string s) 
    {
        int n=s.size();
        
        if(n<26)
            return false;
        
        
        unordered_map<int,int> um;
        
        for(int i=0;i<n;i++) um[s[i]]++;
    
        if(um.size()!=26)
        return false;
        
        return true;
    }
};