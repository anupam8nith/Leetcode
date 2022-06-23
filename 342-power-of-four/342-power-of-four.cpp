class Solution {
public:
    bool isPowerOfFour(int n) 
    {
        // solution 1
//         if(n==1)
//             return true;
//         if(n<=0 || n%4 != 0)
//             return false;
        
        
//         if(ceil(log2(n))==floor(log2(n)))
//         {
//             int zero = (int) ceil(log2(n));
//             if(zero%2==0)
//                 return true;
//             else
//                 return false;
//         }        
        
//         return false;
        
        
        if (n == 0) {
            return false;
        }
        while(n % 4 == 0) {
            n /= 4;
        }
        return n == 1;
        
        
    }
};