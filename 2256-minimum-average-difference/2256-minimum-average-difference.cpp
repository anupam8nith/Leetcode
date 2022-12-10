class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        
        
        int ans = INT_MAX, n = nums.size();
        
        int idx=-1;
        
        
        // vector<int> left(n,-1), right(n,-1);
        
        
        
        // avg from left and from right
        
        long long total = 0, lsum=0;
        
        for(auto x: nums)
            total+=x;
    
        for(int i=0;i<=n-2;i++)
        {
            lsum += nums[i];
            
            int temp = abs(lsum/(i+1)- (total-lsum)/(n-1-i));
                
            if(ans>temp)
            {
                ans = temp;
                idx=i;
            }
        }
        
        if(ans>total/n)
            return n-1;
        
        
        return idx;
        
    }
};


// best soln

// class Solution {
// public:
//   int minimumAverageDifference(vector<int> &nums) {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     long min = 10000000, lsum = 0, usum = 0;
//     int midx = 0, l = nums.size();
//     for (int i = 0; i < l; i++)
//       usum += nums[i];
//     for (int i = 0; i < l; i++) {
//       lsum += nums[i];
//       usum -= nums[i];
//       int lv = abs((lsum / (i + 1)) - (usum ? (usum / (l - i - 1)) : 0));
//       if(lv==0) return i;
//       if (min > lv) {
//         min = lv;
//         midx = i;
//       }
//     }

//     return midx;
//   }
// };