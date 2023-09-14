class Solution {
public:
    int minDeletions(string s) 
    {
        unordered_map<char,int> um;
        int ans=0;
        
        for(auto it: s) um[it]++;
        
        unordered_set<int> used_freq;
        
        for(auto it: um)
        {
            int f = it.second;
            
            while(used_freq.count(f)>0)
            {
                f--;
                ans++;
            }
            
            if(f>0)used_freq.insert(f);
        }
        
        
        
         return ans; 
    }
};