class Solution 
{
public:
    int minOperations(vector<int>& nums) 
    {
        int length = nums.size();
        int minOperations = length;
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int right = 0;

        for (int left = 0; left < nums.size(); left++) 
        {
            while (right < nums.size() && nums[right] < nums[left] + length) right++;

            minOperations = min(minOperations, length - (right - left));
        }

        return minOperations;        
    }
};


// class Solution {
// public:
//     int minOperations(vector<int>& nums) 
//     {
//         int n = nums.size(),ans=INT_MAX;
//         sort(nums.begin(),nums.end());
        
//         for(int i=0;i<n;i++)
//         {
//             int count=0;
//             for(int j=nums[i];j<nums[i]+n;j++)
//                 if(!binary_search(nums.begin(),nums.end(),j)) count++;
            
//             ans = min(ans,count);
//         }
        
//         return ans; 
//     }
// };