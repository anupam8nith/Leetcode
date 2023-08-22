class Solution {
public:
    string convertToTitle(int n) 
    {
    
        string ans ="", str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        if(n<=26)
        {
            ans +=str[n-1];
            return ans;
        }
        
        
        while(n>26)
        {
            int rem = n%26;
            n/=26;
            
            if(rem!=0)
            ans+= str[rem-1];
            else
            {
             ans+=str[25];
             n--;
            }
            
        }
        
        ans+=str[n-1];
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};