class Solution {
public:
    int reverse(int x) 
    {
        long int sum=0,temp=0;
        long int y=abs(x);
        
        while(y>0)
        {
            
            temp = y%10;
            
            sum = sum*10 + temp;
            
            y = y/10;
        }
        
        if(abs(log2(abs(sum))>=31))
            return 0;
        
        if(x<0)
       sum*=-1;
        
        return sum;
        
    }
};