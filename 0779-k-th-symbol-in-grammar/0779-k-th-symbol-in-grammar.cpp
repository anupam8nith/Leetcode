class Solution {
public:
    int kthGrammar(int n, int k) 
    {
        n = 1<<n-1; // n = pow(2,n-1);
        
        bool isSame = true;
        
        while(n!=1)
        {
            n=n>>1;
            
            if(k>n)
            {
                k-=n;
                isSame=!isSame;
            }
        }
        
        return (isSame ? 0: 1);
    }
};