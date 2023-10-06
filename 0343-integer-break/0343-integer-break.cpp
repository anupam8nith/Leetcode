class Solution {
public:
    int integerBreak(int n) 
    {
        if(n==2) return 1;if(n==3) return 2; int twos=0,threes=n/3;
    
        if(n>3 && n%3==0) return ((int)pow(3,threes));
        
        else if(n%3==1)
        {
            threes--;twos+=2;
        }
        else twos++;
        
        return (int)(pow(2,twos)*pow(3,threes));
    }
};