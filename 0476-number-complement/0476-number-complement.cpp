class Solution {
public:
    int findComplement(int num) 
    {
        int ans=0; string s="";
        while(num>0)
        {
            if(num%2)
                s+='0';
            else
                s+='1';
            
            num/=2;
        }  
        
        for(int i=s.size();i>=0;i--)
            if(s[i]=='1')
                ans+=pow(2,i);
        
        return ans;
    }
};