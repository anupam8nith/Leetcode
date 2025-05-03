class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = size(nums), zcount=0,z_idx=-1;
        long long product =1;
        for(int i=0;i<n;i++)
        {   
            int it= nums[i]; 
            if(it!=0)
                product*=it;
            else
                {
                    zcount++;
                    z_idx=i;
                }
        }
        vector<int> ans(n,0);
        if(zcount>1)
            return ans;
        else if(zcount==1)
            {ans[z_idx]=product;}
        else
        {
          for(int i=0;i<n;i++)
            ans[i]=product/nums[i];
        }

        return ans;
    }
};