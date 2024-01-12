class Solution {
public:
    
    int count(string str)
    {
        int ans=0;
        for(int i=0;i<str.size();i++)
        {
            char ch = tolower(str[i]);
            if(ch == 'a'|| ch== 'e' || ch=='i' || ch=='o' || ch=='u')
                ans++;
        }
        
    return ans;
    }
    bool halvesAreAlike(string s) 
    {
        if(count(s.substr(0,s.size()/2)) == count(s.substr(s.size()/2,s.size()/2)))
            return true;
        
        return false;
        
    }
};