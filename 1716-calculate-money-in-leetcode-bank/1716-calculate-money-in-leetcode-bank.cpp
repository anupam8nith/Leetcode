class Solution {
public:
    int totalMoney(int n) 
    {
        int additional=0, tot=0;
        
        for(int i=1;i<=n;i++)
        { 
            tot+=(i%7)+additional;
            
            if(i%7==0)
            {additional++;tot+=7;}
        }
        
        return tot;
    }
};