class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int idxstart=-1, idxend=-1;
        
        if(binary_search(nums.begin(),nums.end(),target))
        { 
            idxstart = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
            idxend= lower_bound(nums.begin(),nums.end(),target+1) - nums.begin()-1;
        }
      
         return {idxstart,idxend};  
    }
};