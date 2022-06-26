class Solution {
public:
    bool checkPossibility(vector<int>& nums) 
    {
        int count = 0;                                                                    //the number of changes
        for(int i = 1; i < nums.size() && count<=1 ; i++){
            if(nums[i-1] > nums[i]){
                count++;
                if(i-2<0 || nums[i-2] <= nums[i])nums[i-1] = nums[i];                    //modify nums[i-1] of a priority
                else nums[i] = nums[i-1];                                                //have to modify nums[i]
            }
        }
        return count<=1;
    }
};

//63 ms

// int count = 0;                               
        
//         for(int i = 1; i < nums.size() && count<=1 ; i++)
//         {
//             if(nums[i-1] > nums[i]){
//                 count++;
//                 if(i-2<0 || nums[i-2] <= nums[i])nums[i-1] = nums[i];                    
//                 else nums[i] = nums[i-1];                                                
//             }
//         }
//         return count<=1;