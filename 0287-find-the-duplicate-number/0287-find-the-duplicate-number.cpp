// #pragma GCC optimize("O3")
class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(false);
        int m = nums.size();
         for(int i=0;i<m;i++)
        {
            //while loop runs till correct number on its place or the necessary condition fails
           while(nums[i]!=i+1) 
           {
               if (nums[i] == nums[ (nums[i] - 1) ])break; //if both are same then no need to run loop
               swap(nums[i],nums[nums[i]-1]); //swap till they are at their required place
           }
        }
        // for(auto it: nums)cout<<it<<" ";

        return nums[m-1];
    }
};