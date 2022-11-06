class Solution {
public:
    bool checkString(string s) 
    {
        int idxa=-1,idxb=-1,n=s.size(),counta=0,countb=0;
        
        int low=0,high=n-1;
        
        while(low<n || high>=0)
        {
            if(s[low]=='b' && countb==0 )
            {   
                countb++;
                idxb=low;
            }
            if(s[high]=='a' && counta==0)
            {   counta++;
                idxa=high;
            }
           
            if(idxa!=-1 && idxb!=-1)
            {
                if(idxa>idxb)
                return false;
                else
                return true;
            }
            if(low<n)
            low++;
            if(high>=0)
            high--;
        }
        
        if(idxa==-1 || idxb==-1)
            return true;
        
     return true;   
    }
};