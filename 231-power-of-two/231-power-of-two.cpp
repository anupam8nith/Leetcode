class Solution {
public:
    bool isPowerOfTwo(int n)
    {
        if(n==0 || n<0)
            return false;
        
        if(ceil(log2(n)) == floor(log2(n)))
            return true;
        else
            return false;
    }
};

// if (n==1){
//             return true;
//         }
//         else if(n==0){
//                 return false;
//             } 
//         while(n!=0){
//             if(n==1){
//                 return true;
//             }
//             else if((n%2)!=0){
//                 return false;
//             }
//             n=n/2;
//         }
//         return true;