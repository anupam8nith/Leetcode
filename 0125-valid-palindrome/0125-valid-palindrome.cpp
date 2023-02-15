class Solution {
public:
    bool isPalindrome(string s) 
    {
        string ans="";
        
        for(auto it: s)
            if(iswalnum(it))
            ans+=(char)tolower(it);
        
        cout<<ans<<endl;

        
        int n=ans.size();
        int m=0;
        int e=n-1;
        
        
        while(m<e)
        {
            if(ans[m]!=ans[e])
                return false;
            
            m++;
            e--;
        }
        
        return true;
    }
};