#define M 1000000007

class Solution {
public:
    
    long long power(long long x, long long n)
    {
        if(n==0)
            return 1;
        else if(!(n&1))
            return power((x*x)%M,n/2);
        else
            return (x*power((x*x)%M,(n-1)/2))%M;
    }
    
    
    int countGoodNumbers(long long n) 
    {
        if(n==0)
            return 1;
        if(n==1)
            return 5;
        
        long long ans = (power(4,n/2)%M)*(power(5,n-n/2)%M) %M;
        
        return (int)ans;
        
    }
};


        // Binary exponentiation

// int binaryExponentiation(int x,int n) {
//     if(n==0) return 1;
//     //n is even
//     else if(n%2 == 0)        
//         return binaryExponentiation(x*x,n/2);
//     //n is odd
//     else                             
//         return x*binaryExponentiation(x*x,(n-1)/2);
// }

        // Modulo exponentiation

// int modularExponentiation(int x, int n, int M) {
//     if(n==0) return 1;
//     //n is even
//     else if(n%2 == 0)        
//         return modularExponentiation((x*x) % M, n/2, M);
//     //n is odd
//     else                             
//         return (x*modularExponentiation((x*x) % M, (n-1)/2, M)) % M;
// }

