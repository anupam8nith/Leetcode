class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) 
    {
        int n = s.size();
        
        vector<int> v(n+1,0);
        
        for(auto a: shifts)
        {
            if(a[2]==1)
            {
                v[a[0]]+=1;
                v[a[1]+1]-=1;
            }
            else
            {
                v[a[0]]-=1;
                
                if(a[1]<n-1)
                v[a[1]+1]+=1;
            }
        }
        
        for(int i=1;i<n;i++)
        {
          v[i]+=v[i-1];
        }
           
        
        // perform operation on string;
        
        for(int i=0;i<n;i++)
        {
            int add = ((s[i]-'a')+ v[i])%26;
            
            add= (add+26)%26;
            
            s[i]= 'a'+add;
        }
            
        return s;
    }
};