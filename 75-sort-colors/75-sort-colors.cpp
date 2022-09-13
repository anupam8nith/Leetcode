//variation of duth national flag algorithm
class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int low=0,mid=0, high=nums.size()-1;
        
        while(mid<=high)
        {
            switch(nums[mid])
            {
                case 0: //nums[mid]==0
                        swap(nums[low++],nums[mid++]);
                        break;
                    
                case 1: //nums[mid]==1
                        mid++;
                        break;
                    
                case 2://nums[mid]==2
                        swap(nums[mid],nums[high--]);
                        break;
            }
        }
    }
};