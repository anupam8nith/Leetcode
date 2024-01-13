class Solution {
public:
    bool search(vector<int>& nums, int target) 
    {
        if(size(nums)==1){if(nums[0]==target) return true; else return false;}
        
        int idx = 0;
        
        for(int i=1;i<nums.size();i++) if(nums[i]<nums[i-1]){idx=i; break;}
        
        
        
        if(binary_search(nums.begin()+idx,nums.end(),target)) return true;
        else if(binary_search(nums.begin(),nums.begin()+idx,target)) return true;
        
        return false;
    }
};