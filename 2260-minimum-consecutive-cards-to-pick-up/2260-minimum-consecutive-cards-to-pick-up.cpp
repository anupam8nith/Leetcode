class Solution {
public:
    int minimumCardPickup(vector<int>& cards) 
    {
        unordered_map<int,int> um;
        
        bool flag =1;
        
        int ans=INT_MAX;
        
        int j = 0;
        for(int i=0;i<cards.size();i++)
        {
            um[cards[i]]++;
            
            while(um[cards[i]]>1)
            {
                flag=0;
                
                um[cards[j]]--;
                
                if(um[cards[i]]==1)
                    ans= min(ans,i-j);
                j++;
            }
        }  
    
        if(flag == 1)
        return -1;
        
       
        return ans+1;   
    }
};