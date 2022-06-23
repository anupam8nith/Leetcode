class Solution {
public:
    bool isPowerOfThree(int n) 
    {   // best of the solution 
        // if(n<= 0)return false;
        // return 1162261467%n == 0;
        
        while(n){
            if(n==1) return true;
            if(n%3!=0) return false;
            n/=3;
        }
        return false;
    }
};