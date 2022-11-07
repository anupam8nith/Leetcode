class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        int n = nums.size();
        
        if(n<=1 || k==0 || n==k)
        return;
        
        vector<int> v(nums);
        
        for(int i=0;i<n;i++)
            nums[(i+k)%n]=v[i];
        
        
        return;
    }
};


// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) 
//     {
//         if(nums.size()<=1)
//         return;
//         std::rotate(nums.begin(),nums.begin()+nums.size()-(k%nums.size()),nums.end());
//         return;
//     }
// };