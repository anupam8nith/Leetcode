/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) 
    {
        long long int s=1,e=n,mid;
        
        while(s<=e)
        {
            mid= s+ (e-s)/2;
            
            int gs = guess(mid);
            
            if(gs==0)
                return mid;
            else if(gs ==1)       
                s=mid+1;
            else
                e=mid-1;
        }
        
        return -1;
    }
};