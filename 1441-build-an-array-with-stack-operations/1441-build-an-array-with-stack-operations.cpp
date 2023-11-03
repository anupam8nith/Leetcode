class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) 
    {
        int sz = target.size(),i=1;vector<string> ans;
        
        for(auto it: target)
        {
            while(i<it)
            {
                ans.push_back("Push");
                ans.push_back("Pop");
                i++;
            }
            
            if(it==i){ans.push_back("Push");i++;}
        }
        
        return ans;
    }
};