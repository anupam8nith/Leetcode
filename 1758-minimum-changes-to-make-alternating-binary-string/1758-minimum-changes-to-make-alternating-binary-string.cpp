class Solution 
{
public:
    
    int minOperations(string s) 
    {
        int n = s.size(),ans=0;

        for(int i=1;i<n;i++)
        {
            if( (s[i-1]=='0' && s[i]=='1') || (s[i-1]=='1' && s[i]=='0') )continue;
            
            if(s[i-1]=='0'){s[i]='1';ans++;continue;}
            if(s[i-1]=='1'){s[i]='0';ans++;continue;}
            
        }
        
        return min(ans,n-ans);
    }
};