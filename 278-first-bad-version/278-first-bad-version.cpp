// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) 
    {
        long long int low=1,high=n,mid;
        
        while(low<high)
        {
            mid= low + (high-low)/2;
            
            if(!isBadVersion(mid))
            {
                low = mid+1;
            }
            else
            {
                high = mid;
            }
        }
        return low;
    }
};