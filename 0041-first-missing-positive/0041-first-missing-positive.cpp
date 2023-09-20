class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        int m = size(nums);
        
        //replace non needed numbers with zero
        for(int i=0;i<m;i++)if(nums[i]<=0 || nums[i]>m) nums[i]=0;
        
        //arrange the position with cyclic sort
        for(int i=0;i<m;i++)
        {
            //while loop runs till correct number on its place or the necessary condition fails
           while(nums[i]!=0 && nums[i]!=i+1) 
           {
               if (nums[i] == nums[ (nums[i] - 1) ])break; //if both are same then no need to run loop
               swap(nums[i],nums[nums[i]-1]); //swap till they are at their required place
           }
        }
        
        //find the missing numbers as all the needed numbers are on its place
        for(int i=0;i<m;i++)if(nums[i]!=i+1)
            return i+1;
        
        return m+1;
    }
};