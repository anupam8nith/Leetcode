class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
       int count = 0;
        
for(int i = 1; i < nums.size(); i++){
    if(nums[i] == nums[i-1]) count++;
    else nums[i-count] = nums[i];
}
return nums.size()-count;
    }
};



//another not optimed approach

class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        unordered_map<int, int> um;
        
        for(long int i=nums.size()-1;i>=0;i--)
            um[nums[i]]++;
        
        nums.clear();
        
        for(auto x: um)
            nums.push_back(x.first);
        
        sort(nums.begin(), nums.end());
        
        return nums.size();
    }
};
