class Solution {
public:
    bool check(vector<int>& nums) 
    {
        int idx=-1,n=nums.size(),count=0;
        
        for(int i=0;i<n-1;i++)
            if(nums[i]>nums[i+1])
            {
                // cout<<i<<endl;
                idx=i;
                count++;
            }
            
            if(idx==-1)
            return true;
        
            if(count>=2)
                return false;
            
            int check=0,wrong=0;
            idx++;
        
            while(check!=n-1)
            {
                if(nums[(idx)%n]>nums[(idx+1)%n])
                    wrong++;
                
                // cout<<nums[(idx)%n]<<" : "<<nums[(idx+1)%n]<<endl;
                    
                if(wrong>0)
                    return false;
                
                check++;
                idx++;
            } 
            return true;
    }
};