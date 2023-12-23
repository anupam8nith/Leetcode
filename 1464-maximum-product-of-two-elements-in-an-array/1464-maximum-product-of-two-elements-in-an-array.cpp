class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int f=INT_MIN,s=INT_MIN;
        
        for(auto &it: nums)
        {
            if(f<=it) {s=f;f=it;}
            else if (s < it && it < f) s = it;
        }
        
        return (f-1)*(s-1);
    }
};