class Solution {
public:
    bool isPowerOfFour(int n) 
    {
        ios_base:: sync_with_stdio(false);
        cin.tie(NULL);
        if(n==1)
            return true;
        if(n<4)
            return false;
        
        int32_t m=n;
        int count=0, i=0;
        

        while(i<=32)
        {
            if(m&1==1)
            {
                if(i%2==0)
                count++;
                else
                return false;
            }
            if(count>1)
                return false;
            m=m>>1;
            i++;
        }
        
        return true;
        
    }
};


//4ms 


// class Solution {
// public:
//     bool isPowerOfFour(int n) 
//     {
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
//     }
// };