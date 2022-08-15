class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        if(nums.size()<=1)
        return;
        std::rotate(nums.begin(),nums.begin()+nums.size()-(k%nums.size()),nums.end());
        return;
    }
};