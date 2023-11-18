class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) 
    {
         int maxf=0;
        long currsum=0;
        sort(nums.begin(),nums.end());
        for(int left=0,right=0;right<nums.size();++right){
            currsum+=nums[right];
            while(currsum+k< static_cast<long>(nums[right])*(right-left+1)){
                currsum-=nums[left];
                left++;
            }
            maxf=max(maxf,right-left+1);
        }
        return maxf;
        
    }
};