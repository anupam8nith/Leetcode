class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        ios_base::sync_with_stdio(NULL);
        cin.tie(NULL);
        
        if(s.size()<=1)
            return s.size();
        
       
        
        int i=0,idx=0, count=0, temp=0;
        
        int flag=1;
        
        while(i< s.size())
        {
             unordered_map<char,int> um;
            
            for(i=idx;i<s.size();i++)
            {
                um[s[i]]++;
                
                if(um[s[i]]>1)
                {
                    flag=0;
                    
                    while(um[s[i]]!=1)
                    {
                        
                        um[s[idx]]--;
                        idx++;
                    }
                    
                    if(temp>count)
                    count = temp;
                    temp=0;
                    
                    um.clear();
                    break;
                }
                temp++;
            }
        }
        if(temp>count)
            count = temp;
        
        if(flag==1)
            count = s.size();
        
        return count;
    }
};