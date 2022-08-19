class Solution {
public:
    bool canConstruct(string ransom, string magazine) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        
        //store the freq of both
        
        unordered_map<char,int> um1,um2;
        
        for(long int i=0;i<magazine.size();i++)
            um2[magazine[i]]++;
        
        for(long int i=0;i<ransom.size();i++)
            um1[ransom[i]]++;
        
        //check if freq of magazine >= ransome 
        
        for(long int i=0;i<ransom.size();i++)
        {
            if(um2[ransom[i]]<um1[ransom[i]])
                return false;
        }
        return true;
        
    }
};