class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
       int low=0,high = nums.size(),mid;
        
 
    // Till low is less than high
    while (low < high) {
        mid = low + (high - low) / 2;
 
        // If X is less than or equal
        // to arr[mid], then find in
        // left subarray
        if (target <= nums[mid]) {
            high = mid;
        }
 
        // If X is greater arr[mid]
        // then find in right subarray
        else {
            low = mid + 1;
        }
    }
   
    // if X is greater than arr[n-1]
    if(low < nums.size() && nums[low] < target) {
       low++;
    }
       
    // Return the lower_bound index
    return low;
}
};


 // return lower_bound(nums.begin(),nums.end(),target) - nums.begin();