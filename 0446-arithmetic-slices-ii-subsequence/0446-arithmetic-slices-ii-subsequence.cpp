class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        vector<map<int,int>> maps(n);

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                long cd=(long)nums[i]-(long)nums[j];
                
                if(cd<=INT_MIN || cd>=INT_MAX) continue;
                
                int count1=maps[j][(int)cd];
                int count2=maps[i][(int)cd];

                ans+=count1;
                maps[i][(int)cd]=count1+count2+1;
            }
        }
        return ans;
    }
};
