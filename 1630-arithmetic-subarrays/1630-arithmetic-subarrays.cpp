class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) 
    {
        int n = l.size();vector<bool> ans(n,true);
        
        for(int i=0;i<n;i++)
        {
            int start=l[i], end=r[i];
            vector<int> temp; for(int j=start;j<=end;j++)temp.push_back(nums[j]);
            
            sort(temp.begin(),temp.end());
            
            int diff=temp[1]-temp[0];
            for(int k=2;k<temp.size();k++)if(temp[k]-temp[k-1]!=diff){ans[i]=false;break;}
            
        }
        
        return ans;
    }
};