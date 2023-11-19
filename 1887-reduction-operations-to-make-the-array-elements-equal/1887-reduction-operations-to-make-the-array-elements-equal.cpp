class Solution 
{
public:
    int reductionOperations(vector<int>& nums) 
    {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        
    sort(nums.begin(),nums.end());

    int res = 0;
    int c = 0;
    for(int i=1; i<nums.size(); i++)
    {
        if(nums[i] != nums[i-1])
        {c++;}
        res += c;
    }
    return res;
}
};