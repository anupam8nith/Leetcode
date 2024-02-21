class Solution {
public:
    int rangeBitwiseAnd(int l, int r) 
    {
        int count=0;

        while(l!=r) 
        {
            l>>=1; 
            r>>=1;
            count++; 
        }
		//count gives the number of zero places from the lsb so left shift m by count.
        return l<<count;
        
    }
};