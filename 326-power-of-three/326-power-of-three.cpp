class Solution {
public:
    bool isPowerOfThree(int n) 
    {
        
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        if (n <= 0)
        return false;
    if (n % 3 == 0)
        return isPowerOfThree(n / 3);
    if (n == 1)
        return true;
    return false;
    }
};



//Mycode 12ms

// class Solution {
// public:
    
    
//     bool solve(int m)
//     {
//         if(m==3 || m==1)
//             return true;
        
//         if(m%3==0)
//             return solve(m/3);
//         else
//             return false;
        
        
//     }
//     bool isPowerOfThree(int n) 
//     {
//         std::ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
        
//          if(n<0 || n==0)
//             return false;
//         return solve(n);
//     }
// };