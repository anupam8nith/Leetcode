class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        
        int sz = size(nums);
        vector<int> n,p;
        
        for(int i=0;i<sz;i++)
        {
            if(nums[i]>0)
                p.push_back(nums[i]);
            else
                n.push_back(nums[i]);
        }
        int i=0,j=0;
        
        for(auto x: p)
        {
            nums[i++]=x;
            nums[i++]=n[j++];
        }
        
        return nums;
    }
};