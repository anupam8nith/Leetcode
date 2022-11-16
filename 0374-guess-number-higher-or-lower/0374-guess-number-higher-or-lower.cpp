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
            
            
            
            if(guess(mid)==0)
                return mid;
            else if(guess(mid) ==1)       
                s=mid+1;
            else
                e=mid-1;
        }
        
        return -1;
    }
};



// int n = input1;

// 	int l =1, r = n, mid,target =1,count =0;

// 	while(target!= n)
// 	{
// 		int temp =0;
// 	while(r>l)
// 	{
// 		mid = l + (r-l)/2;

// 		if(mid==target)
// 		count = max(count,temp);

// 		if(mid>target)
// 		{
// 		r = mid-1;
// 		temp++;
// 		}

// 		if(mid<target)
// 		{
// 			l = mid +1;
// 			temp++;
// 		}
// 	}
// 	target ++;
// 	}

// 	return count;


