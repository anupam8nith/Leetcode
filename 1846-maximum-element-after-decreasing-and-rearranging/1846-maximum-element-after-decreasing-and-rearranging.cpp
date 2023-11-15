class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) 
    {
        int ans=0;
        sort(arr.begin(),arr.end());
        
        for(int &i: arr)
            ans=min(ans+1,i);
        
        return ans;
        
    }
};