class Solution {
public:
    string convert(string &s)
    {
        string ans ="";
        
        for(int i=0;i<s.size();i++)
        {
            int j=i,freq=0;
            while(s[i]==s[j])
            {
                freq++;
                j++;
            }
            ans+=to_string(freq) + s[i];
                
            i=j-1;
            
        }
       
        return ans;
    }
    
    string countAndSay(int n) 
    {
        string st ="1";
        
        if(n==1)
            return st;
        
        for(int i=1;i<n;i++)
            st= convert(st);
    
        return st;
    }
};