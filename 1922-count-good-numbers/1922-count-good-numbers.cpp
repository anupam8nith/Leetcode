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


//Solution

// #define ll long long

// class Solution {
// public:
//     // evens  = 0, 2, 4, 6, 8  => 5 evens
//     // primes = 2, 3, 5, 7     => 4 primes
  
//     int p = 1e9 + 7;
    
//     // calculating x^y efficeiently
//     ll power(long long x, long long y) {
//       long long res = 1;    

//       x = x % p; // Update x if it is more than or equal to p
//       if (x == 0) return 0; 

//       while (y > 0) {
//         // If y is odd, multiply x with result
//         if (y & 1) res = (res*x) % p;
        
//         // we have did the odd step is it was odd, now do the even step
//         y = y>>1; // dividing y by 2, y>>1 is same as y/2
//         x = (x*x) % p;
//       }
//       return res;
//     }
  
//     int countGoodNumbers(long long n) {
//       ll count_of_4s = n/2;
//       ll count_of_5s = n - count_of_4s;
//       ll ans = ((power(4LL, count_of_4s) % p  * power(5LL, count_of_5s) % p) % p);
//       return (int)ans;
//     }
// };
