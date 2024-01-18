class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int result = nums[0], prod1=nums[0],prod2=nums[0], n = size(nums);
        
        for(int i=1;i<n;i++)
        {
            int temp = max({nums[i],prod1*nums[i],prod2*nums[i]});
            prod2= min({nums[i],prod1*nums[i],prod2*nums[i]});
            prod1=temp;
            
            result = max(result,prod1);
        }
        
        return result;
        
    }
};