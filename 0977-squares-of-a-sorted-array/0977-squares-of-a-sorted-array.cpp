class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        vector<int> ans;
        
        int i=0,l,r;
        
        // Find the index where the non-negative numbers start
        while(i < nums.size() && nums[i] < 0) i++;
        
        // Set l to the last negative or zero element
        l = i - 1;
        // Set r to the first positive element
        r = i;
        
        // Add squares of negative elements in reverse order
        while(l >= 0 && r < nums.size())
        {
            if(abs(nums[l]) < nums[r])
                ans.push_back(nums[l] * nums[l--]);
            else 
                ans.push_back(nums[r] * nums[r++]);
        }
        
        // Add remaining squares of negative elements, if any
        while(l >= 0)
            ans.push_back(nums[l] * nums[l--]);
        
        // Add remaining squares of positive elements, if any
        while(r < nums.size())
            ans.push_back(nums[r] * nums[r++]);
        
        return ans;
    }
};
