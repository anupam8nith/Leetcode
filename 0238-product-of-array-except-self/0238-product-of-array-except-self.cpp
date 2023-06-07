class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        long long prod = 1;int zcount=0;
        for(auto x: nums)
        {
            prod*=x;
            if(x==0)zcount++;
        }
        
         //cout<<prod<<endl;
        
        if(zcount>1)
        {
            vector<int> v(nums.size(),0);
            
            return v;
        }
        
        if(zcount==0)
        {
            for(int i=0;i<nums.size();i++)
            {nums[i]=(int)(prod/nums[i]);}
            
            return nums;
        }
        
        if(zcount==1)
        {
            prod=1;
            for(auto x: nums) if(x!=0)  prod*=x;
            
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]==0) nums[i]=prod;
                else nums[i]=0;
            }
            
            return nums;
            
        }
        
        return nums;
            
    }
};