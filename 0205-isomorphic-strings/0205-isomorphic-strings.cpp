class Solution {
public:
    bool helper(string s,string t)
    {
        unordered_map<char,char>mp;
        for(int i=0;i<s.size();i++)
        {
            if(mp[s[i]])
            {
                if(mp[s[i]]!=t[i]) 
                    return false;
            }
            else  mp[s[i]]=t[i];
        }
        return true;
    }

    bool isIsomorphic(string s, string t) 
    {
        return helper(s,t) && helper(t,s);
    }
};