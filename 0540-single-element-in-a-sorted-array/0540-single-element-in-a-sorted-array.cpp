class Solution {
public:
    int bsearch(int l, int r, vector<int>& nums) {
        while (l < r) 
        {
            int mid = l + (r - l) / 2;

            if (mid % 2 == 0) 
            {  
                if (nums[mid] == nums[mid + 1]) l = mid + 2;
                else r = mid;
            } 
            else 
            { 
                if (nums[mid] == nums[mid - 1]) l = mid + 1;
                else r = mid;
            }
        }

        return nums[l];
    }

    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        return bsearch(l, r, nums);
    }
};
