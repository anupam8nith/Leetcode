class Solution 
{
public:
    int maxScore(string s) 
    {
        int count1=0,count0=0,ans=0;
        
        for(auto& ch: s)count1+=(ch=='1');
        
        if(count1==s.size() || count1==0) return s.size()-1;
        
        
        for(int i=0;i<s.size()-1;i++)
        {
            if(s[i]=='0') ++count0;
            else --count1;
            
            ans = max(ans,count1+count0);
        }
        return ans;
        
    }
};