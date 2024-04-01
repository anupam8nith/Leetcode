class Solution {
public:
    void sortColors(vector<int>& nums) {
        int one=0,two=0, n = nums.size(),i=0;
        for(int it: nums) 
        {
            if(it==1)
                one++;
            else if(it==2)
                two++;
        }
        
        while(i<n-(one+two))nums[i++]=0;
        while(i<n-two)nums[i++]=1;
        while(i<n)nums[i++]=2;
        
        return;
        
    }
};