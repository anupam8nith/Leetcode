class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = size(nums);
        for(int i=0;i<n;i++)
            {   //We add something to the existing number so that when we divide it, we get the quotient as the desired number
                int new_value = nums[nums[i]]%n;
                nums[i] += new_value*n;
            }
        
        for(int i=0;i<n;i++)
            nums[i]/=n;

        return nums;
    }
};