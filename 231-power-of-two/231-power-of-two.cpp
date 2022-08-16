class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        if(n==0 || n<0)
            return false;
        
        int32_t m=n; 
        int count=0;
        
        for(int i=0;i<32;i++)
        {
            if(count>1)
                return false;
            if(m&1==1)
                count++;
            m=m>>1;
        }
        
        return true;
    }
};

// my code 1 0ms solution
// class Solution {
// public:
//     bool isPowerOfTwo(int n) 
//     {
// if(n==0 || n<0)
//             return false;
        
//         if(ceil(log2(n)) == floor(log2(n)))
//             return true;
//         else
//             return false;
//    }
//  };