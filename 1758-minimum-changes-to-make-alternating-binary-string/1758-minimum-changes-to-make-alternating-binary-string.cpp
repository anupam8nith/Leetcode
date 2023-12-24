class Solution {
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    
    int minOperations(string s) 
    {
        int count1=0,count0=0, n = s.size(),ans=0;
        
        for(char& ch: s)count1+=(ch=='1');
        count0=n-count1;
        
        for(int i=1;i<n;i++)
        {
            if( (s[i-1]=='0' && s[i]=='1') || (s[i-1]=='1' && s[i]=='0') )continue;
            
            if(s[i-1]=='0'){s[i]='1';ans++;continue;}
            if(s[i-1]=='1'){s[i]='0';ans++;continue;}
            
        }
        
        return min(ans,n-ans);
    }
};