class Solution {
public:
    int maxOperations(vector<int>& nums, int k) 
    {
        unordered_map <int,int> um;
        
        // store frequency in um map
        
        for(int i=0; i<nums.size();i++)
        {
            um[nums[i]]++;
        }
        
        int ans=0;
        int temp=0;
        
        for(auto i=um.begin(); i!=um.end();++i)
        {
            int num = i->first, count=i->second;
            if(k-num==num)
            {
                 temp= count/2 ;
                ans+=temp;
            }
            else if(um.count(k-num))
            {
                
            temp= min( count,um[k-num] );
                
            ans+=temp;
            um[num] -=temp;
            um[k-num] -=temp;
                
            }
        }
        
        return ans;
    }
};