class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) 
    {

        
        vector <long int> ans;  //for stroing the array
        
        
        //declaration
        
        long int start=0;
        long int end=nums.size()-1;
        long int l=0;
        int sorted=0;
        
        //loop1 for copying
        
        for(long int i=0; i<nums.size(); i++)
        {
            ans.push_back(nums[i]);
        }
    
        
        //sort the copied ans array
        
        sort(ans.begin(), ans.end());
        
        for(long int i=0;i<ans.size();i++)
        {
            sorted=1;
            if(nums[i]!=ans[i])
            {
                sorted=0;
                break;
            }
        }

        
        
        if(sorted==1)
            return 0;
        else
        {
        
        // loop2 for finding the two indexes
        
       for(long int j=0;j<nums.size();j++)
       {
           if(ans[j]!=nums[j])
           {
               start=j;
               break;
           }
       }
        
        for(long int k=ans.size()-1;k>=0;k--)
        {
            if(nums[k]!=ans[k])
            {
                end=k;
                break;
            }
        }
          
         if(start==0&&end==0) return 0;
        
        l= end-start+1;
        return l;
        }
        
    }
};