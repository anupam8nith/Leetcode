class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());
        
        int left = 0, right = nums.back() - nums.front();
        
        // Binary search for the smallest k-th distance
        while (left < right) 
        {
            int mid = left + (right - left) / 2;
            
            // Count pairs with distance <= mid
            int count = 0, j = 0;
            for (int i = 0; i < nums.size(); ++i) 
            {
                while (j < nums.size() && nums[j] - nums[i] <= mid) j++;
                count += j - i - 1; // Count pairs with current i
            }
            
            // Adjust binary search bounds based on the count
            if (count < k)
                left = mid + 1;
            else
                right = mid;
        }
        
        return left;
    }
};
