class Solution {
public:
    bool wordPattern(string pattern, string s) 
    {
        int n = s.size(), i=0,j=0,sz=pattern.size(); 
        unordered_map<char,string> um;
        unordered_map<string,char> mp;
        
        while(i<n && j<sz)
        {
            string temp;
            
            while(s[i]!=' ' && i<n)temp+=s[i++];
            
            if(!um.count(pattern[j]) && !mp.count(temp))
            {
                um[pattern[j]]=temp;
                mp[temp] = pattern[j++];
            }
            else if(um[pattern[j]]!= temp || mp[temp]!=pattern[j++]) 
                return false;
            
            if(s[i]==' ')i++;
            
        }
        return i==n && j==sz;
    }
};