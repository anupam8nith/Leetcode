class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
       int window = 0; 
        for (int i=0;i<nums.size();i++)
        {
	        if (nums[i]==0){
                window++; 
            }
            else if (window > 0) 
            {
	            int t = nums[i];
	            nums[i]=0;
	            nums[i-window]=t;
            }
         }
    }
};