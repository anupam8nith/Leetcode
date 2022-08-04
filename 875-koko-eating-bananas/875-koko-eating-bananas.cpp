class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        long int n= piles.size();
        
        if(n==h)
        return *max_element(piles.begin(), piles.end());
        
        long int low = 1;
        long int high = *max_element(piles.begin(), piles.end());
        long int mid= low + (high-low)/2, sum=0;
        
        while(low<high)
        {
            mid= low + (high-low)/2;
            sum=0;
            for(long int i=0;i<n;i++)
            {
                sum+= (piles[i]+mid-1)/mid;
            }
            
           
            if(sum<=h)
                high = mid;
            else
            {
                low = mid+1;
            }
        }
        
        return low;
    }
};


// long long int sum=0,minn=0;
    
        
//         minn = *min_element(piles.begin(),piles.end()); 
        
//         while(sum!=h)
//         { 
            // sum=0;
            // for(long int i=0;i<n;i++)
            // {
            //     sum+= (piles[i]+minn-1)/minn;
            // }
        
//             if(sum==h)
//              return minn;
//             else //decide minn value by binary search
//             {
//                 long int low= minn, high= *max_element(piles.begin(),piles.end());
//                 long int mid = low + (high-low)/2;
                
//                 if(sum==h)
//              return minn;
//                 else if(sum>h)
//                     high = mid;
//                 else if(sum<h)
//                     low = mid;
                
//                 minn= mid;
//             }
//         }
        