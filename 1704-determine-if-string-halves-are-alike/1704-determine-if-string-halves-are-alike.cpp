class Solution {
public:
    bool halvesAreAlike(string s) 
    {
        int n = size(s), a=0,b=0;
        
        for(int i=0;i<n/2;i++)
        {
            s[i]=tolower(s[i]);
            if(s[i]==97 || s[i]==101 || s[i]==105 || s[i]==111 || s[i]==117)
                a++;
        }
        
        for(int i=n/2;i<n;i++)
        {
             s[i]=tolower(s[i]);
            if(s[i]==97 || s[i]==101 || s[i]==105 || s[i]==111 || s[i]==117)
                b++;
        }
        
        if(a==b)
        return true;
        
        return false;
    }
};